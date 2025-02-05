use strict;
use XML::DOM;
use XML::Tidy;
use File::Util;

my $PATHSEP=File::Util->SL;
my $TRUE=1;
my $FALSE=0;

my @webrequests = ();
my $lrscript = &readArguments(@ARGV);

my %tables;
my %paramsubs;
my %dynamicParams;
my @curHTTPHeaders;

&getParametersFromLR();

my @actions = &getActionFilesFromLR();
&parseActionFiles();
&writeJM();

exit;

sub readArguments
{
	my @ARGS = @_;
	
	my $usage = <<END;
lr2jm.pl

USAGE:

lr2jm.pl <LoadRunner Script Path>
END

	die $usage if ($#ARGS < 0);
	my $script = $ARGS[0];
	die "$script: $!\r\n$usage" unless (-d $script);
	return $script;
}
# -------------------------------------------------------------------------
# Function: getParametersFromLR
# Description:
#   This function processes a LoadRunner parameter (.prm) file to extract 
#   parameter definitions and associated data tables. It performs the following:
#
#   1. Reads the .prm file associated with the LoadRunner script.
#   2. Parses parameter blocks to extract relevant metadata, such as:
#      - ParamName (name of the parameter)
#      - Type (parameter type, e.g., Table)
#      - Table (associated data table file)
#      - ColumnName (column within the data table)
#   3. For parameters of type "Table":
#      - Opens the associated table file (e.g., dp_Name.dat).
#      - Creates a new CSV file with a modified filename to avoid conflicts.
#      - Cleans the data by removing header rows and blank lines.
#      - Extracts column names and maps them to parameter names for substitution.
#   4. Populates a hash (%tables) to store table data, including:
#      - CSV filename
#      - Column names extracted from the table.
#   5. Updates a substitution hash (%paramsubs) to map parameter names to 
#      their respective column names for later use.
#
# Notes:
#   - Ensures all file operations are error-checked and provides detailed
#     error messages if a file cannot be accessed or processed.
#   - Designed to support the conversion of LoadRunner parameter data
#     for compatibility with other tools (e.g., JMeter).
#
# Parameters:
#   None (relies on global variables like $lrscript, $PATHSEP, %tables, and %paramsubs).
#
# Output:
#   - Creates new CSV files for parameter data tables.
#   - Updates global hashes (%tables and %paramsubs) with processed data.
# -------------------------------------------------------------------------

sub getParametersFromLR
{
	my $f = File::Util->new();
	my $prm = $lrscript.$PATHSEP.$f->strip_path($lrscript).".prm";
	return unless (-f $prm);
	
	open (PRM, "<$prm") or die "Unable to open $prm\r\n$!\r\n$^E";

	local $/ = '[';
	my @params;
	
	while (<PRM>) {
		push (@params, $_) unless ($. == 1);
	}
	close PRM;
		
	foreach my $param (@params) {
		$_ = $param;
		my ($type) = m/Type="(.*)"/;
		my ($paramname) = m/ParamName="(.*)"/;
		my ($delimiter) = m/Delimiter="(.*)"/;
		my ($columnname) = m/ColumnName="(.*)"/;
		my ($table) = m/Table="(.*)"/;
		
		next unless ($type eq "Table");
		
		if (not exists($tables{$table})){
			$tables{$table}=$table;
			my $l2j_tablefile = $table;
			$l2j_tablefile =~ s/\./_/g;
			$l2j_tablefile = $l2j_tablefile.".csv";
			
			my @tabledata;
			push (@tabledata,$l2j_tablefile);
			
			local $/="\n";
			my @columns;
			
			my $tablefile = $lrscript.$PATHSEP.$table;
			$l2j_tablefile = $lrscript.$PATHSEP.$l2j_tablefile;
			
			open (PARAMFILE, "<$tablefile") or die "Trying to configure parameter $paramname:\r\n\tunable to open parameter data file $tablefile: $!\r\n$^E";
			open (L2JFILE,">$l2j_tablefile") or die "unable to open parameter data file $l2j_tablefile: $!\r\n$^E";
			
			while (<PARAMFILE>) {
				print L2JFILE unless ($.==1 || m/^\s*$/);
				@columns = split /,/ if $.==1;
			}
			close L2JFILE;
			close PARAMFILE;

			chomp(@columns);
			
			push (@tabledata,@columns);
			$tables{$table}=\@tabledata;
		}
		
		if ($columnname =~ m/^Col (\d+)/){
			my $col = $1;
			my $colname = ${$tables{$table}}[$col];
			$paramsubs{$paramname}=$colname;
		} else {
			$paramsubs{$paramname}=$columnname;
		}
		
	}
	
}
# -------------------------------------------------------------------------
# Function: getActionFilesFromLR
# Description:
#   This function processes a LoadRunner `.usr` file to extract references
#   to action files (`.c` files) associated with the script. These files
#   typically represent different parts of the script logic, such as
#   initialization (`vuser_init.c`), main actions (`Action.c`), and cleanup
#   (`vuser_end.c`).
#
# Steps:
#   1. Constructs the full path to the `.usr` file for the given LoadRunner script.
#   2. Opens the `.usr` file for reading and processes each line:
#      - Trims unnecessary whitespace.
#      - Checks if the line references a `.c` file.
#      - Extracts the `.c` file name by removing everything before and 
#        including the `=` character.
#      - Adds the extracted `.c` file name to an array of actions.
#   3. Closes the `.usr` file after reading.
#   4. Returns the list of action files found in the `.usr` file.
#
# Parameters:
#   None (relies on the global variable $lrscript to locate the `.usr` file).
#
# Output:
#   - Returns an array containing the names of all `.c` files referenced in the `.usr` file.
#
# Notes:
#   - Provides error handling for file operations with descriptive error messages.
#   - Used to automate the identification of LoadRunner script components.
#
# Example:
#   Input `.usr` file:
#     [General]
#     Replay=Action.c
#     Init=vuser_init.c
#     End=vuser_end.c
#
#   Output:
#     @actions = ("Action.c", "vuser_init.c", "vuser_end.c");
# -------------------------------------------------------------------------

sub getActionFilesFromLR
{
	my $f = File::Util->new();
	my $usr = $lrscript.$PATHSEP.$f->strip_path($lrscript).".usr";
	my @actions;
	
	open (USR, "<$usr") or die "Unable to open $usr\r\n$!\r\n$^E";
	while (<USR>) {
		my $usrline = $_;
		$usrline =~ s/\s*$//;
		if ($usrline =~ m/\.c$/){
			$usrline =~ s/^.*?=//;
			push(@actions,$usrline);
		}
	}
	close USR;

	return @actions;
}
# This function processes a list of action files to extract and handle LoadRunner function calls.
# It reads the action files, processes each function in them, and invokes the corresponding subroutines 
# based on the function names like `web_url`, `web_submit_data`, `lr_start_transaction`, etc.
sub parseActionFiles
{	
    # Iterate over each action file in the @actions array
	foreach my $action (@actions) {	
        # Open the action file and read its contents into @actioncontents array
	    open (ACTION, "<${lrscript}".File::Util->SL.$action) or die "couldn't open action file: $!\r\n$^E";
	    my @actioncontents = <ACTION>;
	    close ACTION;
	    
         # Clean each line in the action contents by removing leading/trailing spaces and quotes
	    for (my $i=0;$i<=$#actioncontents;$i++) {
	        my $line = $actioncontents[$i];
	        $actioncontents[$i] =~ s/^\s+//;
	        $actioncontents[$i] =~ s/\s+$//;
	        $actioncontents[$i] =~ s/^"//;
	        $actioncontents[$i] =~ s/"$//;
			
	    }
	    
		# Join the cleaned contents into a single string for easier processing
		my $actioncontentsSTR = join("", @actioncontents);
        # Use regex to extract the portion of the string after the first '{' character
		$actioncontentsSTR =~ /([^{]*){(.*)/;
        # Split the extracted portion into individual function calls (separated by ')')
	    my @functions = split(/\);/,$2);
	    
          # Process each extracted function call
	    foreach (@functions) {
			
			#print "function = $_\n";
			# Match function name and its arguments using regex
	        my ($lrfunc,$lrargs) = m/([^\(]*)\((.*)/;
			
			
			#my @result = extract_bracketed($1)
			
			
			 # If a valid function name is found, process the function  
	        if (defined($lrfunc)){
			
				# Call specific subroutines based on the function name
				#print "function = $lrfunc\n";
	            $_ = $lrfunc;
	            &web_url($lrargs) if m/web_url/;
	            &web_submit_data($lrargs) if m/web_submit_data/;
	            &web_custom_request($lrargs) if m/web_custom_request/;
	            &web_reg_save_param($lrargs) if m/web_reg_save_param/; #and not(m/web_reg_save_param_regexp/);
				&lr_start_transaction($lrargs) if m/lr_start_transaction/; 
				&lr_end_transaction($lrargs) if m/lr_end_transaction/; 
				&web_add_auto_header($lrargs) if m/web_add_auto_header/; 
				&web_add_header($lrargs) if m/web_add_header/; 
				&web_reg_find($lrargs) if m/web_reg_find/;
			}
	    }
	}
} # parseActionFile


# This function, lr_start_transaction, is designed to initiate a transaction in a performance test script.
# It takes a single argument - the name of the transaction to be tracked (e.g., "Blazedemo_T01_Launch").
# The function performs the following:
# - It extracts the transaction name from the provided argument.
# - It removes any surrounding double quotes from the transaction name (if present).
# - It creates a hash containing the function name ("lr_start_transaction") and the cleaned-up transaction name.
# - The hash is then pushed into an array (@webrequests), which stores the transaction data for later use.

# Example usage:
# lr_start_transaction("Blazedemo_T01_Launch");

# Example stored data:
# After calling lr_start_transaction("Blazedemo_T01_Launch"), the @webrequests array will contain:
# [
#     {
#         function       => "lr_start_transaction",  # The name of the function that started the transaction
#         transactionname => "Blazedemo_T01_Launch"  # The name of the transaction
#     }
# ]

# The stored data can later be accessed and used for reporting, logging, or other processing tasks.
# The array @webrequests will keep a record of all transactions initiated during the script's execution.

# Function to handle the start of a transaction
sub lr_start_transaction
{
    # Shift the first argument (transaction name) passed to the function.
    # The shift function removes and returns the first value from the argument list.
    my $arguments = shift;
    
    # Split the argument string by commas into an array (@arguments).
    # This allows the function to handle multiple arguments (although we are using just one in this case).
    my @arguments = split(/,/, $arguments);
    
    # Get the transaction name from the first element of the arguments array.
    # In this case, it's expected to be a string like "Blazedemo_T01_Launch".
    my $transactionName = $arguments[0];
    
    # Remove any surrounding double quotes from the transaction name (if present).
    # For example, "Blazedemo_T01_Launch" will become Blazedemo_T01_Launch.
    $transactionName =~ s/"//g;
    
    # Create a hash to store relevant request data for the transaction.
    # This will contain the function name and the transaction name.
    my %requestdata;
    $requestdata{function} = "lr_start_transaction";  # The function that initiated the transaction.
    $requestdata{transactionname} = $transactionName; # The name of the transaction to track.
    
    # Create a reference (pointer) to the request data hash to pass it around more efficiently.
    my $hashref = \%requestdata;
    
    # Push the hash reference into the @webrequests array for later processing.
    # This will store all the transaction data for further logging, reporting, or analysis.
    push(@webrequests, $hashref);
}

# The lr_end_transaction function is used to mark the end of a transaction in the performance test script.
# It takes a single argument - the name of the transaction being completed (e.g., "Blazedemo_T01_Launch").
# The function performs the following:
# - It extracts the transaction name from the provided argument.
# - It removes any surrounding double quotes from the transaction name (if present).
# - It creates a hash containing the function name ("lr_end_transaction") and the cleaned-up transaction name.
# - The hash is then pushed into an array (@webrequests), which tracks the end of the transaction.

# Example usage:
# lr_end_transaction("Blazedemo_T01_Launch");

# Example stored data:
# After calling lr_end_transaction("Blazedemo_T01_Launch"), the @webrequests array will contain:
# [
#     {
#         function        => "lr_start_transaction",      # Record of when the transaction was started
#         transactionname => "Blazedemo_T01_Launch"      # Name of the transaction that started
#     },
#     {
#         function        => "lr_end_transaction",        # Record of when the transaction ended
#         transactionname => "Blazedemo_T01_Launch"      # Name of the transaction that ended
#     }
# ]

# The @webrequests array will hold the data for both the start and end of transactions.
# This helps in tracking the complete lifecycle of a transaction from start to finish, which is important
# for measuring the performance of the system and generating accurate performance reports.
# The stored data will typically be used for transaction timing and analysis during the execution of the test script.

sub lr_end_transaction
{
	my $arguments = shift;
    my @arguments = split(/,/,$arguments);
    my $transactionName = $arguments[0];
    $transactionName =~ s/"//g;
	
	my %requestdata;
	$requestdata{function} = "lr_end_transaction";
	$requestdata{transactionname} = $transactionName;
	
	my $hashref = \%requestdata;
    push(@webrequests,$hashref);
}

sub web_url
{
    my $arguments = shift;
    my @arguments = split(/,/,$arguments);
    my $stepname = $arguments[0];
    $stepname =~ s/"//g;
    
    my %requestdata;
    $requestdata{stepname} = $stepname;
    $requestdata{method}='GET';
    
    foreach my $argument (@arguments){
        $argument =~ s/"//g;
        if ($argument =~ m/^URL=https*:\/\/(.*?)((\/.*)|(:(.*?)(\/.*)))/) {
            $requestdata{domain}= $1;
            
			if(defined $5) {
				$requestdata{path}=$6;
				$requestdata{port}=$5;
			} else {
				$requestdata{path}=$2;
			}
        }
        if ($argument =~ m/^Mode=(.*)/) {
            if ($1 =~ /HTML/) {
                $requestdata{image_parser}='true';    
            } else {
                $requestdata{image_parser}='false';
            }
        }
    }

	my %params = %dynamicParams;
	$requestdata{params}=\%params;
	foreach my $key (keys %dynamicParams){
		delete $dynamicParams{$key};
	}
	
	
	my @headers = @curHTTPHeaders;
	$requestdata{headers}=\@headers;
	undef @curHTTPHeaders;
	
    my $hashref = \%requestdata;
    push(@webrequests,$hashref);
}

sub web_submit_data
{
    my $arguments = shift;
    my @arguments = split(/,/,$arguments);
    my $stepname = shift(@arguments);
    $stepname =~ s/"//g;
    
    my %requestdata;
    my @itemdata;
    $requestdata{stepname} = $stepname;
    
    foreach my $argument (@arguments){
        $argument =~ s/^\s*"*//g;
        $argument =~ s/"*\s*$//g;
        
        if ($argument =~ m/^Action=https*:\/\/(.*?)((\/.*)|(:(.*?)(\/.*)))/) {
            $requestdata{domain}= $1;
     
			
			if(defined $5) {
				$requestdata{path}=$6;
				$requestdata{port}=$5;
			} else {
				$requestdata{path}=$2;
			}
        }
        if ($argument =~ m/^Mode=(.*)/) {
            if ($1 =~ /HTML/) {
                $requestdata{image_parser}='true';    
            } else {
                $requestdata{image_parser}='false';
            }
        }
        if ($argument =~ m/^Method=(.*)/) {
            $requestdata{method}=$1;    
        }
        # if ($argument =~ m/^Name=(.*)/) {
        	# push(@itemdata,$1);
        # }
        # if ($argument =~ m/^Value=(.*)/) {
        	# push(@itemdata,$1);
        # }
        # if (($argument =~ m/LAST/) & ($#itemdata > 0)) {
        	# $requestdata{itemdata} = \@itemdata;
        # }
    }
	
	
	my @itemDataNameSet = ( $arguments =~ m/Name=((?:[^"\\]|\\.)*)"/g );
	my @itemValueNameSet = ( $arguments =~ m/Value=((?:[^"\\]|\\.)*)"/g  );
	
	my $i = 0;
	foreach my $curName (@itemDataNameSet) {

		push(@itemdata,$curName);
		push(@itemdata,$itemValueNameSet[$i]);
		$i = $i + 1;
	}
	if ($#itemdata > 0) {

        $requestdata{itemdata} = \@itemdata;
    }
	
	my %params = %dynamicParams;
	$requestdata{params}=\%params;
	foreach my $key (keys %dynamicParams){
		delete $dynamicParams{$key};
	}
	
	my @headers = @curHTTPHeaders;
	$requestdata{headers}=[@headers];
	undef @curHTTPHeaders;
		
	
    my $hashref = \%requestdata;
    push(@webrequests,$hashref);
}

# The 'web_submit_data' function processes and structures data for an HTTP request to be sent
# during a performance test. It takes a comma-separated string of arguments, extracts specific 
# details such as the URL, method (GET/POST), headers, and body data (e.g., form data), and
# formats this information into a structured hash. The function then stores the formatted request
# data into the global '@webrequests' array for tracking and reporting purposes.
#
# Key elements processed:
# - 'stepname' : A unique identifier for the request step.
# - 'domain'   : Extracted from the URL, specifies the host.
# - 'path'     : Extracted from the URL, specifies the resource path.
# - 'method'   : HTTP method (e.g., GET, POST).
# - 'data'     : The body data (e.g., form submission data or JSON payload).
# - 'headers'  : Custom headers (e.g., Content-Type, Accept).
# - 'params'   : Dynamic parameters (if any) added during runtime.
#
# Example of how the input string is processed:
# web_submit_data("{dp_Host}", 
#     "URL=https://{dp_Host}/submit", 
#     "Method=POST", 
#     "Data=username=test&password=12345", 
#     "EncType=application/x-www-form-urlencoded", 
#     "Referer=https://{dp_Host}/login", 
#     "Header=Accept: application/json", 
#     "LAST");
#
# This would result in a structured request being added to '@webrequests' with all extracted
# data including headers, URL components, method, and body data for further use in testing.


sub web_custom_request
{
    my $arguments = shift;

	
    my @arguments = split(/,/,$arguments);
    my $stepname = shift(@arguments);
    $stepname =~ s/"//g;
    
    my %requestdata;
    my @itemdata;
    $requestdata{stepname} = $stepname;
	
	$arguments =~ m/Body=((?:[^"\\]|\\.)*)"/;
	my $body = $1;
	$body =~ s/\\(["\\])/"qq|\\$1|"/gee; #remove escape character forward slash
    $requestdata{bodydata} = $body;
	
    foreach my $argument (@arguments){
        $argument =~ s/^\s*"*//g;
		
        
        $argument =~ s/"*\s*$//g;

        
        if ($argument =~ m/^URL=https*:\/\/(.*?)((\/.*)|(:(.*?)(\/.*)))/) {
            $requestdata{domain}= $1;
			
			if(defined $5) {
				$requestdata{path}=$6;
				$requestdata{port}=$5;
			} else {
				$requestdata{path}=$2;
			}
			
        }
        if ($argument =~ m/^Mode=(.*)/) {
            if ($1 =~ /HTML/) {
                $requestdata{image_parser}='true';    
            } else {
                $requestdata{image_parser}='false';
            }
        }
        if ($argument =~ m/^Method=(.*)/) {
            $requestdata{method}=$1;    
        }
		
		if ($argument =~ m/^EncType=(.*)/) {
			print "EncType= $1\n";
			my @header = ("Content-Type", $1);
		
            push (@curHTTPHeaders, \@header);
        }

    }

	my %params = %dynamicParams;
	$requestdata{params}=\%params;
	foreach my $key (keys %dynamicParams){
		delete $dynamicParams{$key};
	}
	
	my @headers = @curHTTPHeaders;
	$requestdata{headers}=\@headers;
	undef @curHTTPHeaders;

	
    my $hashref = \%requestdata;
    push(@webrequests,$hashref);
}

# This script handles performance tracking and dynamic data extraction during a load test.
# We use the `lr_start_transaction` to mark the beginning of a transaction, 
# then issue a `web_custom_request` to simulate an HTTP request, 
# followed by a `web_reg_save_param` to dynamically capture values from the response.
# Finally, the transaction is ended with `lr_end_transaction` for performance tracking.
# 
# The `@webrequests` array stores all actions as hashes:
# 1. `lr_start_transaction` is called to start the transaction.
# 2. `web_custom_request` sends the HTTP request with dynamic data (e.g., URL, method, headers).
# 3. `web_reg_save_param` extracts dynamic parameters (like flight number) from the response body.
# 4. `lr_end_transaction` marks the end of the transaction.
#
# This structure allows tracking of each step in the request/response cycle, 
# and ensures that dynamic parameters (e.g., flight number) are captured and can be reused in subsequent requests.
#
# The @webrequests array is populated as follows:
# @webrequests = (
#     # After calling lr_start_transaction("Blazedemo_T01_Launch")
#     {
#         function         => "lr_start_transaction",      # Marks the start of the transaction.
#         transactionname  => "Blazedemo_T01_Launch"      # Name of the transaction.
#     },
    
#     # After calling web_custom_request
#     {
#         stepname         => "{dp_Host}",                 # The step name (e.g., dp_Host).
#         bodydata         => "https://{dp_Host}/",        # Full URL with dynamic placeholder.
#         domain           => "{dp_Host}",                 # The domain part of the URL (dp_Host).
#         path             => "/",                         # The URL path.
#         method           => "GET",                       # HTTP method (GET).
#         resource         => "0",                         # Resource type (0 for HTTP).
#         reccontenttype   => "text/html",                 # Expected content type (HTML).
#         referer          => "",                          # Empty Referer field.
#         snapshot         => "t1.inf",                    # Snapshot file used for tracking.
#         mode             => "HTTP",                      # HTTP request mode.
#         headers          => [                             # Request headers.
#             ["Content-Type", "text/html"]               # Content-Type header.
#         ],
#         params           => {},                          # Parameters to send in the request (none in this case).
#     },
    
#     # After calling web_reg_save_param_regexp (for dynamic parameter extraction)
#     {
#         paramname        => "dc_Flightno",               # Name of the saved parameter.
#         regex            => "input type=\"hidden\" value=\"(.*?)\" name=\"flight\">",  # Regex to extract flight number.
#         group            => 1,                           # Use first capturing group.
#         ordinal          => "1",                         # Ordinal for match selection.
#         scope            => "BODY",                      # Scope for regex search (BODY of the response).
#     },
    
#     # After calling lr_end_transaction("Blazedemo_T01_Launch")
#     {
#         function         => "lr_end_transaction",        # Marks the end of the transaction.
#         transactionname  => "Blazedemo_T01_Launch"      # Name of the transaction being ended.
#     }
# );

# This approach ensures that dynamic data like flight numbers are captured and reused, 
# while also allowing for detailed performance tracking of each transaction.

sub web_reg_save_param
{
    my $arguments = shift;
    my @arguments = split(/,/,$arguments);
    my $paramname;
    
    if ($arguments[0] !~ /=/) {
        # First argument is the parameter name without "ParamName="
        $paramname = shift(@arguments);
    } else {
        shift(@arguments) =~ /ParamName=(.*)/;
        $paramname = $1;
    }
    
    $paramname=~s/"//g; 
    
    $arguments =~ m/RegExp=((?:[^"\\]|\\.)*)"/;
    my $regex = $1;
    
    my $group = 1;
    my $ordinal = "1";
    my $scope = "BODY";
    
    if ($arguments =~ m/Group=(\d+)/) {
        $group = $1;
    }
    
    if ($arguments =~ m/Ordinal=(ALL|\d+)/) {
        $ordinal = $1;
    }
    
    if ($arguments =~ m/Scope=(ALL|BODY|HEADERS)/) {
        $scope = $1;
    }
	
	 if ($arguments =~ m/Ord=(ALL|\d+)/) {
        $ordinal = $1;
    }
    
    if ($arguments =~ m/Search=(ALL|Body|Headers)/) {
        $scope = $1;
    }
    
    if (defined $regex) {
        $regex =~ s/\\(["\\])/"qq|\\$1|"/gee; #remove escape character forward slash
        
        $dynamicParams{$paramname} = {
            'regex' => $regex,
            'group' => $group,
            'ordinal' => $ordinal,
            'scope' => $scope
        };
    }
    else {
        my ($LB,$RB);
        
        $arguments =~ m/LB(\/IC)?=((?:[^"\\]|\\.)*)"/;
        $LB=$2;
        
        $arguments =~ m/RB(\/IC)?=((?:[^"\\]|\\.)*)"/;
        $RB=$2;
        
        $LB =~ s/\\(["\\])/"qq|\\$1|"/gee; #remove escape character forward slash
        $RB =~ s/\\(["\\])/"qq|\\$1|"/gee; #remove escape character forward slash
        
        $dynamicParams{$paramname} = {
            'regex' => $LB."(.*?)".$RB,
            'group' => $group,
            'ordinal' => $ordinal,
            'scope' => $scope
        };
    }
    $paramsubs{$paramname}=$paramname; 
}

# The `web_reg_find` function is used to define an assertion that searches for specific text in the HTTP response during a performance test. 
# The function takes a string of arguments, extracts the 'Text' to search for and the 'Search' location (e.g., BODY, HEADERS), and stores this information in a global hash `%dynamicParams{assertions}`.
# Assertions allow for validating that specific text exists in the HTTP response, and are useful for verifying that the system behaves as expected during load testing.

# Example Usage:
# web_reg_find("Text=Success,Search=BODY");

# After the function call, the following data is stored in the `@webrequests` array for later validation:
# @webrequests = (
#     {
#         function => "web_reg_find", 
#         text => "Success", 
#         search => "BODY"
#     }
# );

# This ensures that the word "Success" is searched for in the body of the HTTP response during the test, and the result can be validated.

sub web_reg_find {
    my $arguments = shift;

    # Extract the Text parameter
    my ($text) = $arguments =~ /Text=([^,]+)/;
    $text =~ s/^"//;
    $text =~ s/"$//;

    # Extract the Search parameter
    my ($search) = $arguments =~ /Search=([^,]+)/;
    $search =~ s/^"//;
    $search =~ s/"$//;

    # Create the assertion hash
    my %assertion;
    $assertion{function} = "web_reg_find";
    $assertion{text} = $text;
    $assertion{search} = $search;

    # Store the assertion in the dynamicParams hash
    push(@{$dynamicParams{assertions}}, \%assertion);
}



sub web_add_header
{
	
	my $arguments = shift;
    my @arguments = split(/,/,$arguments,2);
    
    
    foreach my $argument (@arguments){
    	$argument =~ s/^\s*"*//g;
        $argument =~ s/"*\s*$//g;
    }
	
	push (@curHTTPHeaders, \@arguments);
	
}


sub web_add_auto_header
{
    my $arguments = shift;
    my @arguments = split(/,/,$arguments,2);
    
    foreach my $argument (@arguments){
        $argument =~ s/^\s*"*//g;
        $argument =~ s/"*\s*$//g;
    }
    
    push (@curHTTPHeaders, \@arguments);
}


sub writeJM
{
	#my $jmx = $lrscript.$PATHSEP.$lrscript.".jmx";
	my $f = File::Util->new();
	my $jmx = $lrscript.$PATHSEP.$f->strip_path($lrscript).".jmx";
    open (JMETER,">$jmx") or die "couldn't open file for write: $!\r\n$^E";
    
    my $jmeter = XML::DOM::Document->new;
    my $xml_pi = $jmeter->createXMLDecl('1.0');
    my $root = $jmeter->createElement('jmeterTestPlan');
    $root->setAttribute('version','1.2');
    $root->setAttribute('properties',' 1.8');
    my $roothashtree = $jmeter->createElement('hashTree');
    my $testplan = $jmeter->createElement('TestPlan');
    my $testplanhashtree = $jmeter->createElement('hashTree');
    my $threadgroup = $jmeter->createElement('ThreadGroup');
    my $threadgrouphashtree = $jmeter->createElement('hashTree');
    my $configtestelement = $jmeter->createElement('ConfigTestElement');
    my $configtesthashtree = $jmeter->createElement('hashTree');
    my $cookiemanager = $jmeter->createElement('CookieManager');
    my $cookiemanagerhashtree = $jmeter->createElement('hashTree');
    
    my $property;
    my $elementproperty;
    
    $root->appendChild($roothashtree);
    $roothashtree->appendChild($testplan);
    $roothashtree->appendChild($testplanhashtree);
    $testplanhashtree->appendChild($threadgroup);
    $testplanhashtree->appendChild($threadgrouphashtree);
    $threadgrouphashtree->appendChild($configtestelement);
    $threadgrouphashtree->appendChild($configtesthashtree);
    $threadgrouphashtree->appendChild($cookiemanager);
    $threadgrouphashtree->appendChild($cookiemanagerhashtree);
    
    
    $testplan->setAttribute('guiclass','TestPlanGui');
    $testplan->setAttribute('testclass','TestPlan');
    $testplan->setAttribute('testname','LR2JM Test Plan: '.$lrscript);
    $testplan->setAttribute('enabled','true');
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','TestPlan.functional_mode');
        $property->addText('false');
    $testplan->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','TestPlan.comments');
    $testplan->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','TestPlan.user_define_classpath');
    $testplan->appendChild($property);
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','TestPlan.serialize_threadgroups' );
        $property->addText('false');
    $testplan->appendChild($property);
        $elementproperty = $jmeter->createElement('elementProp');
        $elementproperty->setAttribute('name','TestPlan.user_defined_variables');
        $elementproperty->setAttribute('elementType','Arguments');
        $elementproperty->setAttribute('guiclass','ArgumentsPanel');
        $elementproperty->setAttribute('testclass','Arguments');
        $elementproperty->setAttribute('testname','User Defined Variables');
        $elementproperty->setAttribute('enabled','true');
            $property = $jmeter->createElement('collectionProp');
            $property->setAttribute('name','Arguments.arguments');
        $elementproperty->appendChild($property);
    $testplan->appendChild($elementproperty);
    
    $threadgroup->setAttribute('guiclass','ThreadGroupGui');
    $threadgroup->setAttribute('testclass','ThreadGroup');
    $threadgroup->setAttribute('testname','LR2JM Thread Group');
    $threadgroup->setAttribute('enabled','true');
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','ThreadGroup.scheduler');
        $property->addText('false');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','ThreadGroup.num_threads');
        $property->addText('1');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','ThreadGroup.duration');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','ThreadGroup.delay');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('longProp');
        $property->setAttribute('name','ThreadGroup.start_time' );
        $property->addText('1187292555000');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','ThreadGroup.on_sample_error');
        $property->addText('continue');
    $threadgroup->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','ThreadGroup.ramp_time');
        $property->addText('1');
    $threadgroup->appendChild($property);
        $elementproperty = $jmeter->createElement('elementProp');
        $elementproperty->setAttribute('name','ThreadGroup.main_controller');
        $elementproperty->setAttribute('elementType','LoopController');
        $elementproperty->setAttribute('guiclass','LoopControlPanel');
        $elementproperty->setAttribute('testclass','LoopController');
        $elementproperty->setAttribute('testname','Loop Controller');
        $elementproperty->setAttribute('enabled','true');
            $property = $jmeter->createElement('stringProp');
            $property->setAttribute('name','LoopController.loops');
            $property->addText('1');
        $elementproperty->appendChild($property);
            $property = $jmeter->createElement('boolProp');
            $property->setAttribute('name','LoopController.continue_forever' );
            $property->addText('false');
        $elementproperty->appendChild($property);
    $threadgroup->appendChild($elementproperty);
        $property = $jmeter->createElement('longProp');
        $property->setAttribute('name','ThreadGroup.end_time');
        $property->addText('1187292555000');
    $threadgroup->appendChild($property);
    
    $configtestelement->setAttribute('guiclass','HttpDefaultsGui');
    $configtestelement->setAttribute('testclass','ConfigTestElement');
    $configtestelement->setAttribute('testname','HTTP Request Defaults');
    $configtestelement->setAttribute('enabled','true');
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.domain');
        $property->addText('');
    $configtestelement->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.path');
    $configtestelement->appendChild($property);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.port');
        $property->addText('80');
    $configtestelement->appendChild($property);
        $elementproperty = $jmeter->createElement('elementProp');
        $elementproperty->setAttribute('name','HTTPsampler.Arguments');
        $elementproperty->setAttribute('elementType','Arguments');
        $elementproperty->setAttribute('guiclass','HTTPArgumentsPanel');
        $elementproperty->setAttribute('testclass','Arguments');
        $elementproperty->setAttribute('testname','User Defined Variables');
        $elementproperty->setAttribute('enabled','true');
            $property = $jmeter->createElement('collectionProp');
            $property->setAttribute('name','Arguments.arguments');
        $elementproperty->appendChild($property);
    $configtestelement->appendChild($elementproperty);
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.protocol');
    $configtestelement->appendChild($property);
              
    $cookiemanager->setAttribute('guiclass','CookiePanel');
    $cookiemanager->setAttribute('testclass','CookieManager');
    $cookiemanager->setAttribute('testname','HTTP Cookie Manager');
    $cookiemanager->setAttribute('enabled','true');
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','CookieManager.clearEachIteration');
        $property->addText('false');
    $cookiemanager->appendChild($property);
        $property = $jmeter->createElement('collectionProp');
        $property->setAttribute('name','CookieManager.cookies');
    $cookiemanager->appendChild($property);
    
# This script generates a CSV Data Set Config element for JMeter dynamically for each table in the %tables hash.
# For each table, it creates a JMeter CSV Data Set element that will read data from the specified CSV file 
# and assign the column names as variable names for parameterized testing in JMeter.
# The script ensures that the CSV data can be reused (via the 'recycle' property) and specifies the delimiter as a comma (',').
# It also sets up the appropriate attributes such as the filename, encoding, and column variables, 
# and appends this configuration to the Thread Group's hash tree.
# The CSV Data Set Config allows JMeter to read and use external CSV data for running parameterized tests.

    foreach my $key (keys %tables){
    	my ($datafile,@columns) = @{$tables{$key}};
    	$elementproperty = $jmeter->createElement('CSVDataSet');
    	$elementproperty->setAttribute('guiclass','TestBeanGUI');
    	$elementproperty->setAttribute('testclass','CSVDataSet');
    	$elementproperty->setAttribute('testname','LR2JM Data Set');
    	$elementproperty->setAttribute('enabled','true');
    	$property=$jmeter->createElement('stringProp');
    	$property->setAttribute('name','delimiter');
    	$property->addText(',');
    	$elementproperty->appendChild($property);
    	$property=$jmeter->createElement('stringProp');
    	$property->setAttribute('name','fileEncoding');
    	$elementproperty->appendChild($property);
    	$property=$jmeter->createElement('stringProp');
    	$property->setAttribute('name','filename');
    	$property->addText($datafile);
    	$elementproperty->appendChild($property);
    	$property=$jmeter->createElement('boolProp');
    	$property->setAttribute('name','recycle');
    	$property->addText('true');
    	$elementproperty->appendChild($property);
    	$property=$jmeter->createElement('stringProp');
    	$property->setAttribute('name','variableNames');
    	$property->addText(join(',',@columns));
    	$elementproperty->appendChild($property);
    	
    	$threadgrouphashtree->appendChild($elementproperty);
    	my $hashtree = $jmeter->createElement('hashTree');
        $threadgrouphashtree->appendChild($hashtree);
    }
    #print "tables done\r\n";
    
	my $transactionController = $jmeter->createElement('TransactionController');
	$transactionController->setAttribute('guiclass','TransactionControllerGui');
    $transactionController->setAttribute('testclass','TransactionController');
    $transactionController->setAttribute('testname','Transaction Controller');
    $transactionController->setAttribute('enabled','true');
	my $boolProp = $jmeter->createElement('boolProp');
	$boolProp->setAttribute('name','TransactionController.parent');
	$boolProp->addText('true');
	$transactionController->appendChild($boolProp);
			
	$threadgrouphashtree->appendChild($transactionController);
	my $transactionhashtree = $jmeter->createElement('hashTree');
	$threadgrouphashtree->appendChild($transactionhashtree);
	
	my $usingExplicitTransaction = 0;
	my $isEmptyTransaction = 1;
	
    foreach my $requestdata (@webrequests) {
		# Add Transactions
		my $lrfunction = ${$requestdata}{'function'};
        my $httpsampler = $jmeter->createElement('HTTPSampler');
        my $hashtree = $jmeter->createElement('hashTree');

		
		
		
		if ($lrfunction eq "lr_start_transaction") {
		
			if (not($usingExplicitTransaction) && not($isEmptyTransaction)) {
			

				$transactionController = $jmeter->createElement('TransactionController');
				$threadgrouphashtree->appendChild($transactionController);
				$transactionhashtree = $jmeter->createElement('hashTree');
				$threadgrouphashtree->appendChild($transactionhashtree);
				
				$usingExplicitTransaction = 1;
				$isEmptyTransaction = 1;
			}
			
			$transactionController->setAttribute('guiclass','TransactionControllerGui');
        	$transactionController->setAttribute('testclass','TransactionController');
        	$transactionController->setAttribute('testname',${$requestdata}{'transactionname'});
        	$transactionController->setAttribute('enabled','true');
			$boolProp = $jmeter->createElement('boolProp');
			$boolProp->setAttribute('name','TransactionController.parent');
			$boolProp->addText('true');
			$transactionController->appendChild($boolProp);
			
			
			next;
		}


		if ($lrfunction eq "lr_end_transaction") {
			
			$usingExplicitTransaction = 0;
			$isEmptyTransaction = 1;
			
			$transactionController = $jmeter->createElement('TransactionController');
			$transactionController->setAttribute('guiclass','TransactionControllerGui');
        	$transactionController->setAttribute('testclass','TransactionController');
        	$transactionController->setAttribute('testname','Transaction Controller');
        	$transactionController->setAttribute('enabled','true');
			$boolProp = $jmeter->createElement('boolProp');
			$boolProp->setAttribute('name','TransactionController.parent');
			$boolProp->addText('true');
			$transactionController->appendChild($boolProp);
			
			$threadgrouphashtree->appendChild($transactionController);
			$transactionhashtree = $jmeter->createElement('hashTree');
			$threadgrouphashtree->appendChild($transactionhashtree);
			
			next;
		}

		
		if ($isEmptyTransaction) {
			$isEmptyTransaction = 0;
		}
		
		
		
		
		if($#{ ${$requestdata}{'headers'} } >= 0) {
			
			#Add header elements uder $hashtree
			my $header = $jmeter->createElement('HeaderManager');
			$header->setAttribute('guiclass','HeaderPanel');
			$header->setAttribute('testclass','HeaderManager');
			$header->setAttribute('testname','HTTP Header Manager');
			$header->setAttribute('enabled','true');
			$hashtree->appendChild($header);
			$hashtree->appendChild($jmeter->createElement('hashTree'));
			
			my $collectionProp = $jmeter->createElement('collectionProp');
			$collectionProp->setAttribute('name','HeaderManager.headers');
			$header->appendChild($collectionProp);
			
			for my $i ( 0 .. $#{ ${$requestdata}{'headers'} } ) {
		
			
				my $elementProp = $jmeter->createElement('elementProp');
				$elementProp->setAttribute('name','');
				$elementProp->setAttribute('elementType','Header');
				$collectionProp->appendChild($elementProp);
				
				my $stringPropName = $jmeter->createElement('stringProp');
				$stringPropName->setAttribute('name','Header.name');
				$stringPropName->addText(paramSubstitution(${$requestdata}{headers}[$i][0]));
				$elementProp->appendChild($stringPropName);
				
				my $stringPropValue = $jmeter->createElement('stringProp');
				$stringPropValue->setAttribute('name','Header.value');
				$stringPropValue->addText(paramSubstitution(${$requestdata}{headers}[$i][1]));
				$elementProp->appendChild($stringPropValue);
			}
		}

		
        foreach my $dynamicparams (${$requestdata}{'params'}){
    my %dynamicparams = %{$dynamicparams};
    foreach my $param (keys %dynamicparams){
        next if $param eq 'assertions';
        my $regex_data = $dynamicparams{$param};
        my $regexextractor = $jmeter->createElement('RegexExtractor');
        $regexextractor->setAttribute('guiclass','RegexExtractorGui');
        $regexextractor->setAttribute('testclass','RegexExtractor');
        $regexextractor->setAttribute('testname','LR2JM Regex Extractor');
        $regexextractor->setAttribute('enabled','true');
        $hashtree->appendChild($regexextractor);
        
        my $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.useHeaders');
        #$property->addText($regex_data->{'scope'} eq 'HEADERS' ? 'true' : 'false' || $regex_data->{'scope'} eq 'Headers' ? 'true' : 'false');
		if ($regex_data->{'scope'} eq 'HEADERS' || $regex_data->{'scope'} eq 'Headers') {
		$property->addText('true');
		} else {
		$property->addText('false');
		}
        $regexextractor->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.refname');
        $property->addText($param);
        $regexextractor->appendChild($property); 
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.regex');
        $property->addText($regex_data->{'regex'});
        $regexextractor->appendChild($property); 
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.template');
        $property->addText('$'.$regex_data->{'group'}.'$');
        $regexextractor->appendChild($property); 
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.default');
        $regexextractor->appendChild($property); 
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','RegexExtractor.match_number');
        $property->addText($regex_data->{'ordinal'} eq 'ALL' ? '-1' : $regex_data->{'ordinal'});
        $regexextractor->appendChild($property); 
        
        my $regexhashtree = $jmeter->createElement('hashTree');
        $hashtree->appendChild($regexhashtree);
    }
}
		
				if (exists ${$requestdata}{params}{assertions}) {
		foreach my $assertion (@{${$requestdata}{params}{assertions}}) {
			if ($assertion->{function} eq "web_reg_find") {
				my $responseAssertion = $jmeter->createElement('ResponseAssertion');
				$responseAssertion->setAttribute('guiclass', 'AssertionGui');
				$responseAssertion->setAttribute('testclass', 'ResponseAssertion');
				$responseAssertion->setAttribute('testname', 'Response Assertion');
				$responseAssertion->setAttribute('enabled', 'true');
				
				my $collectionProp = $jmeter->createElement('collectionProp');
				$collectionProp->setAttribute('name', 'Asserion.test_strings');
				
				my $stringProp = $jmeter->createElement('stringProp');
				$stringProp->setAttribute('name', 'Assertion.test_string'); # Set a proper name for the stringProp element
				$stringProp->addText($assertion->{text});
				
				$collectionProp->appendChild($stringProp);
				$responseAssertion->appendChild($collectionProp);
				
				my $stringProp2 = $jmeter->createElement('stringProp');
				$stringProp2->setAttribute('name', 'Assertion.test_field');
				if (exists $assertion->{search} && $assertion->{search} eq 'Headers') {
					$stringProp2->addText('Assertion.response_headers');
				} else {
					$stringProp2->addText('Assertion.response_data');
				}
				$responseAssertion->appendChild($stringProp2);
				
				my $boolProp = $jmeter->createElement('boolProp');
				$boolProp->setAttribute('name', 'Assertion.assume_success');
				$boolProp->addText('false');
				$responseAssertion->appendChild($boolProp);
				
				my $intProp = $jmeter->createElement('intProp');
				$intProp->setAttribute('name', 'Assertion.test_type');
				$intProp->addText('2');
				$responseAssertion->appendChild($intProp);
				
				$hashtree->appendChild($responseAssertion);
				$hashtree->appendChild($jmeter->createElement('hashTree'));
			}
		}
		delete ${$requestdata}{params}{assertions};
	}



        
        $transactionhashtree->appendChild($httpsampler);
        $transactionhashtree->appendChild($hashtree);
        
        $httpsampler->setAttribute('guiclass','HttpTestSampleGui');
        $httpsampler->setAttribute('testclass','HTTPSampler');
        $httpsampler->setAttribute('testname',${$requestdata}{'stepname'});
        $httpsampler->setAttribute('enabled','true');
        
        $elementproperty = $jmeter->createElement('elementProp');
        $elementproperty->setAttribute('name','HTTPsampler.Arguments');
        $elementproperty->setAttribute('elementType','Arguments');
        $elementproperty->setAttribute('guiclass','HTTPArgumentsPanel');
        $elementproperty->setAttribute('testclass','Arguments');
        $elementproperty->setAttribute('enabled','true');
        my $collectionproperty = $jmeter->createElement('collectionProp');
        $collectionproperty->setAttribute('name','Arguments.arguments');
        $elementproperty->appendChild($collectionproperty);
        $httpsampler->appendChild($elementproperty);
        
        my $itemdataref = ${$requestdata}{'itemdata'};
        
		
		if($#{$itemdataref} eq -1 ){
			
			my $boolProp = $jmeter->createElement('boolProp');
			$boolProp->setAttribute('name','HTTPSampler.postBodyRaw');
			$boolProp->addText('true');
			$httpsampler->appendChild($boolProp);
			
			my $httpargproperty = $jmeter->createElement('elementProp');
			$httpargproperty->setAttribute('name','');
        	$httpargproperty->setAttribute('elementType','HTTPArgument');
			$collectionproperty->appendChild($httpargproperty);
			
			$property = $jmeter->createElement('boolProp');
	        $property->setAttribute('name','HTTPArgument.always_encode');
	        $property->addText('false');
	        $httpargproperty->appendChild($property); 
		
        	my $value = paramSubstitution(${$requestdata}{'bodydata'});
			
			$property = $jmeter->createElement('stringProp');
	        $property->setAttribute('name','Argument.value');
	        $property->addText($value);
	        $httpargproperty->appendChild($property);

	        $property = $jmeter->createElement('stringProp');
	        $property->setAttribute('name','Argument.metadata');
	        $property->addText('=');
	        $httpargproperty->appendChild($property); 			
		}
		
        for (my $i=0;$i < $#{$itemdataref};$i+=2) {
        	my $name = paramSubstitution(${$itemdataref}[$i]);
        	my $value = paramSubstitution(${$itemdataref}[$i+1]);
        	
        	my $httpargproperty = $jmeter->createElement('elementProp');
        	$httpargproperty->setAttribute('name','');
        	$httpargproperty->setAttribute('elementType','HTTPArgument');
        	$collectionproperty->appendChild($httpargproperty);
        	
        	$property = $jmeter->createElement('boolProp');
	        $property->setAttribute('name','HTTPArgument.always_encode');
	        $property->addText('false');
	        $httpargproperty->appendChild($property); 
	        
	        $property = $jmeter->createElement('stringProp');
	        $property->setAttribute('name','Argument.value');
	        $property->addText($value);
	        $httpargproperty->appendChild($property); 
	        
	        $property = $jmeter->createElement('stringProp');
	        $property->setAttribute('name','Argument.metadata');
	        $property->addText('=');
	        $httpargproperty->appendChild($property); 
        	
        	$property = $jmeter->createElement('boolProp');
	        $property->setAttribute('name','HTTPArgument.use_equals');
	        $property->addText('true');
	        $httpargproperty->appendChild($property); 
	        
	        $property = $jmeter->createElement('stringProp');
	        $property->setAttribute('name','Argument.name');
	        $property->addText($name);
	        $httpargproperty->appendChild($property); 
        	
        }
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.domain');
        $property->addText(paramSubstitution(${$requestdata}{'domain'}));        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.port');    
		$property->addText(paramSubstitution(${$requestdata}{'port'}));   
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.protocol');     
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.method');
        $property->addText(${$requestdata}{'method'}); 
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.contentEncoding');     
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.path');
        $property->addText(paramSubstitution(${$requestdata}{'path'}));        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','HTTPSampler.follow_redirects');
        $property->addText('true');        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','HTTPSampler.auto_redirects');
        $property->addText('true');        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','HTTPSampler.use_keepalive');
        $property->addText('true');        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','HTTPSampler.DO_MULTIPART_POST');
        $property->addText('false');        
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.mimetype');     
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.FILE_NAME');     
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.FILE_FIELD');     
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('boolProp');
        $property->setAttribute('name','HTTPSampler.image_parser');
        $property->addText(${$requestdata}{'image_parser'});        
        $httpsampler->appendChild($property);
    	
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.monitor');
        $property->addText('true');    
        $httpsampler->appendChild($property);
        
        $property = $jmeter->createElement('stringProp');
        $property->setAttribute('name','HTTPSampler.embedded_url_re');     
        $httpsampler->appendChild($property);
        
    }
    
    my $jmeterxml = $xml_pi->toString.$root->toString;

    print JMETER $jmeterxml;    
    close JMETER;

    my $xmltidy = XML::Tidy->new('filename' => $jmx);
    $xmltidy->tidy();
    print $xmltidy->write();
    
}
 
# paramSubstitution function:
# This function performs parameter substitution in the provided input string.
# It searches for placeholders in the format {param_name} and replaces them with
# corresponding values from the %paramsubs hash.

# Steps:
# 1. The input string is passed as an argument to the function.
# 2. The function iterates through each key in the %paramsubs hash (which contains
#    parameter names and their substitution values).
# 3. For each parameter in %paramsubs, the function performs a global substitution
#    to replace occurrences of {param_name} in the input string with the value 
#    from %paramsubs.
# 4. The function returns the modified input string after all substitutions.

# Example:
# Input: "Username: {user}, Password: {password}"
# %paramsubs = ( 'user' => 'test_user', 'password' => 'test_password' )
# Output: "Username: test_user, Password: test_password"

sub paramSubstitution
{
    my $inputstring = shift;
    foreach my $param (keys %paramsubs) {
		#print "$param\n";
        $inputstring =~ s/{$param}/\${$paramsubs{$param}}/g;
    }
    return $inputstring;
}
