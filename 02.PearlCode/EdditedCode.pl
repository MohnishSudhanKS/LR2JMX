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
my $add_event_regex = qr/\*{6} Add Event For Transaction With Id (\d+) \*{6}.*?web_url\("([^"]+)"/s;

# Data structures to store transaction data
my %transaction_host_map;
my %transaction_date_map;
my %transaction_timestamp_map;
my %transaction_full_data_map;
my %transaction_response_headers_map;
my %transaction_request_path_map;
my %transaction_charset_map;
my %transaction_lb_map;  # Map to store lb tag values
my @transaction_ids;
my $current_transaction_id;
my $transaction_data = '';
my $parsing_response_header = 0;

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
        next;
    }

    # Extract lb value from Add Event block
    if ($line =~ /web_url\("([^"]+)"/) {
        $transaction_lb_map{$current_transaction_id} = $1;
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
        $writer->endTag("httpSample");
    }

    $writer->endTag("testResults");
    close $xml_fh;
    print "XML file with <httpSample> entries generated successfully.\n";
}

sub display_transaction_details {
    print "\nAvailable Transaction IDs:\n";
    print join(", ", @transaction_ids), "\n";
    print "-----------------------------------\n";

    while (1) {
        print "Enter a transaction ID to view details (or type 'quit' to exit): ";
        chomp(my $input = <STDIN>);

        if ($input eq 'quit') {
            print "Exiting transaction viewer. Goodbye!\n";
            last;
        }

        if (exists $transaction_full_data_map{$input}) {
            print "Details for Transaction ID $input:\n";
            print $transaction_full_data_map{$input}, "\n";

            my $file_path = "$output_directory/Transaction_$input.txt";
            open my $file, '>', $file_path or die "Cannot open file $file_path: $!\n";
            print $file $transaction_full_data_map{$input};
            close $file;

            print "Details written to $file_path\n";
        } else {
            print "Transaction ID $input not found. Please try again.\n";
        }
    }
}

write_http_samples_to_xml($output_directory);
display_transaction_details();