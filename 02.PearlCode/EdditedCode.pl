use strict;
use warnings;
use File::Basename;
use File::Path qw(make_path);
use Time::Piece;
use XML::Writer;

# Input and output file paths
my $input_file_path = 'C:\PerfomanceTesting\Learning\LR2JMX\03.Scripts\DemoBlaze\CodeGenerationLog.txt';
my $output_directory = 'C:/PerfomanceTesting/Learning/LR2JMX/03.Scripts/DemoBlaze/Record';

# Regular expressions
my $transaction_start_regex = qr/\*{5} Request Header For Transaction With Id (\d+) \*{5}/;
my $response_header_start_regex = qr/\*{6} Response Header For Transaction With Id (\d+) \*{6}/;
my $host_fetcher_regex = qr/Host:\s+([^\s]+)/;
my $response_date_regex = qr/Date:\s+(.+? GMT)(?:\r?\n|$)/;
my $request_line_regex = qr/^(POST|GET|PUT|DELETE|PATCH)\s+(https?:\/\/[^\s]+)(\s+HTTP\/\d+\.\d+)/;
my $content_type_regex = qr/Content-Type:\s.*?charset=([^\s;]+)/;
my $add_event_regex = qr/\*{6} Add Event For Transaction With Id (\d+) \*{6}.*?(web_url|web_custom_request)\("([^"]+)"/s;
my $response_body_start_regex = qr/\*{6} Response Body For Transaction With Id (\d+) \*{6}/;
my $response_body_end_regex = qr/\$\$\$\$\$\$ Response Body For Transaction With Id \d+ Ended \$\$\$\$\$\$/;

# Data structures
my %transaction_host_map;
my %transaction_date_map;
my %transaction_timestamp_map;
my %transaction_full_data_map;
my %transaction_response_headers_map;
my %transaction_request_path_map;
my %transaction_charset_map;
my %transaction_lb_map;
my %transaction_response_header_content_map;
my %transaction_request_header_content_map;
my %transaction_response_body_map;
my @transaction_ids;
my $current_transaction_id;
my $transaction_data = '';
my $parsing_response_header = 0;
my $parsing_request_header = 0;
my $parsing_response_body = 0;
my $response_header_content = '';
my $request_header_content = '';
my $response_body_content = '';

# Open and process the input file
open my $reader, '<', $input_file_path or die "Cannot open file $input_file_path: $!\n";
make_path($output_directory) unless -d $output_directory;

while (my $line = <$reader>) {
    chomp $line;

    # Check for a new transaction start
    if ($line =~ $transaction_start_regex) {
        if (defined $current_transaction_id) {
            $transaction_full_data_map{$current_transaction_id} = $transaction_data;
        }

        $current_transaction_id = $1;
        push @transaction_ids, $current_transaction_id;
        $transaction_data = '';
        $parsing_response_header = 0;
    }

# Check for the start of a response header
if ($line =~ $response_header_start_regex) {
    $parsing_response_header = 1;
    $current_transaction_id = $1;
    $response_header_content = "$line\n";  # Ensure the first line is captured
    next;
}

# Stop capturing response headers
if ($line =~ /Response Header For Transaction With Id \d+ Ended/) {
    $parsing_response_header = 0;
	
	# Escape special XML characters
	$response_header_content =~ s/&/&amp;/g;
	$response_header_content =~ s/</&lt;/g;
	$response_header_content =~ s/>/&gt;/g;
	
    # Clean response header
	$response_header_content =~ s/\n{3,}/\n\n/g;
	$response_header_content =~ s/^.*Response Header For Transaction With Id \d+.*\n//;
	
	# Remove duplicate lines
	my %seen;
	$response_header_content = join("\n", grep { !$seen{$_}++ } split("\n", $response_header_content));
	
	# Escape special XML characters
	$response_header_content =~ s/&/&amp;/g;
	$response_header_content =~ s/</&lt;/g;
	$response_header_content =~ s/>/&gt;/g;
	
	# Ensure a newline at the end before closing </responseHeader>
	$response_header_content .= "\n" unless $response_header_content =~ /\n$/;
	
	# Store cleaned response header
	$transaction_response_header_content_map{$current_transaction_id} = $response_header_content;

    next;
}


# Capture response header content, ensuring no blank lines are lost
if ($parsing_response_header && $line !~ $response_header_start_regex) {
    $response_header_content .= "$line\n" unless $response_header_content =~ /\Q$line\E/;  # Avoid duplicate lines
}

# Detect start of request header
if ($line =~ /\*{6} Request Header For Transaction With Id (\d+) \*{6}/) {
    $parsing_response_header = 0;  # Stop parsing response header
    $current_transaction_id = $1;
    $parsing_request_header = 1;
    $request_header_content = "$line\n";  # Capture the first line
    next;
}

# Stop capturing request headers
if ($line =~ /Request Header For Transaction With Id \d+ Ended/) {
    $parsing_request_header = 0;
	
	# Escape special XML characters
	$request_header_content =~ s/&/&amp;/g;
	$request_header_content =~ s/</&lt;/g;
	$request_header_content =~ s/>/&gt;/g;

    # Clean request header
	$request_header_content =~ s/\n{3,}/\n\n/g;
	$request_header_content =~ s/^.*Request Header For Transaction With Id \d+.*\n//;
	
	# Remove duplicate lines
	my %seen;
	$request_header_content = join("\n", grep { !$seen{$_}++ } split("\n", $request_header_content));
	
	# Escape special XML characters
	$request_header_content =~ s/&/&amp;/g;
	$request_header_content =~ s/</&lt;/g;
	$request_header_content =~ s/>/&gt;/g;
	
	# Ensure a newline at the end before closing </requestHeader>
	$request_header_content .= "\n" unless $request_header_content =~ /\n$/;
	
	# Store cleaned request header
	$transaction_request_header_content_map{$current_transaction_id} = $request_header_content;

    next;
}

if ($line =~ $response_body_start_regex) {
    $parsing_response_body = 1;
    $current_transaction_id = $1;
    $response_body_content = '';  # Reset content
    next;
}

if ($line =~ $response_body_end_regex) {
    $parsing_response_body = 0;

    # Escape XML special characters
    $response_body_content =~ s/&/&amp;/g;
    $response_body_content =~ s/</&lt;/g;
    $response_body_content =~ s/>/&gt;/g;

    # Store response body
    $transaction_response_body_map{$current_transaction_id} = $response_body_content;
    next;
}

if ($parsing_response_body) {
    $response_body_content .= "$line\n";  # Capture full response body
}

# Capture request header content
if ($parsing_request_header && $line !~ /\*{6} Request Header For Transaction With Id \d+ \*{6}/) {
    $request_header_content .= "$line\n" unless $request_header_content =~ /\Q$line\E/;  # Avoid duplicates
}


    # Extract lb value from Add Event block (web_url or web_custom_request)
    if ($line =~ /\*{6} Add Event For Transaction With Id (\d+) \*{6}/ .. $line =~ /\*{6} Add Event For Transaction With Id \d+ Ended \*{6}/) {
        if ($line =~ /(web_url|web_custom_request)\("([^"]+)"/) {
            $transaction_lb_map{$current_transaction_id} = $2;
        }
    }

    # Parse the response header's first line
    if ($parsing_response_header && $line =~ /^HTTP\/1\.1 (\d{3}) (.+)$/) {
        $transaction_response_headers_map{$current_transaction_id} = {
            'rc' => $1,
            'rm' => $2,
        };
        next;
    }

    # Extract charset from the Content-Type line
    if ($parsing_response_header && $line =~ $content_type_regex) {
        $transaction_charset_map{$current_transaction_id} = $1;
        next;
    }

    # Extract host information
    if ($line =~ $host_fetcher_regex) {
        my $host = $1;
        $transaction_host_map{$current_transaction_id} = $host;
    }

    # Extract Date from the response header
    if ($line =~ $response_date_regex) {
        my $date = $1;
        $transaction_date_map{$current_transaction_id} = $date;
        my $t = Time::Piece->strptime($date, "%a, %d %b %Y %H:%M:%S GMT");
        my $timestamp = $t->epoch * 1000;

        while (grep { $_ == $timestamp } values %transaction_timestamp_map) {
            $timestamp++;
        }
        $transaction_timestamp_map{$current_transaction_id} = $timestamp;
    }

    # Capture the request line (URL) for the lb tag
    if ($line =~ $request_line_regex) {
        my $url = $2;
        if ($url =~ m{https?://[^/]+(/.*)}) {
            my $path = $1;
            $transaction_request_path_map{$current_transaction_id} = $path;
        }
    }

    if ($parsing_response_header) {
        $response_header_content .= $line . "\n" if $line =~ /\S/;  # Skip blank lines
    }

    if (defined $current_transaction_id) {
        $transaction_data .= $line . "\n";
    }
}

if (defined $current_transaction_id) {
    $transaction_full_data_map{$current_transaction_id} = $transaction_data;
}

close $reader;

sub write_http_samples_to_xml {
    my ($output_directory) = @_;

    my $xml_file_path = "$output_directory/transactions.xml";
    open my $xml_fh, '>', $xml_file_path or die "Cannot open file $xml_file_path: $!\n";

    my $writer = XML::Writer->new(OUTPUT => $xml_fh, UNSAFE => 1, DATA_MODE => 1, EOL => "\n");
    $writer->xmlDecl("UTF-8");
    $writer->startTag("testResults", version => "1.2");

    foreach my $transaction_id (@transaction_ids) {
        my $timestamp = $transaction_timestamp_map{$transaction_id};
        my $lb_value = $transaction_lb_map{$transaction_id} // "";
        my $response_code = $transaction_response_headers_map{$transaction_id}{'rc'} // "200";
        my $response_message = $transaction_response_headers_map{$transaction_id}{'rm'} // "OK";
        my $charset = $transaction_charset_map{$transaction_id} // "";

        $writer->startTag("httpSample",
            t => "0",
            it => "0",
            lt => "0",
            ct => "0",
            ts => $timestamp,
            s => "true",
            lb => $lb_value,
            rc => $response_code,
            rm => $response_message,
            tn => "",
            dt => "",
            de => $charset,
            by => "184",
            sby => "621",
            sc => "1",
            ec => "0",
            ng => "0",
            na => "0",
            hn => "L-INE-HM15T93"
        );

# Add cleaned response headers
if (exists $transaction_response_header_content_map{$transaction_id}) {
    $writer->startTag("responseHeader", class => "java.lang.String");
    $writer->raw($transaction_response_header_content_map{$transaction_id});
    $writer->endTag("responseHeader");
}

# Add cleaned request headers (newly added part)
if (exists $transaction_request_header_content_map{$transaction_id}) {
    $writer->startTag("requestHeader", class => "java.lang.String");
    $writer->raw($transaction_request_header_content_map{$transaction_id});
    $writer->endTag("requestHeader");
}
# Add response data content
if (exists $transaction_response_body_map{$transaction_id}) {
    $writer->startTag("responseData", class => "java.lang.String");
    $writer->raw($transaction_response_body_map{$transaction_id});
    $writer->endTag("responseData");
}

# Add response file tag after response data
$writer->startTag("responseFile", class => "java.lang.String");
$writer->endTag("responseFile");


        $writer->endTag("httpSample");
    }

    $writer->endTag("testResults");
    close $xml_fh;
    print "XML file with <httpSample> entries generated successfully.\n";
}

write_http_samples_to_xml($output_directory);
