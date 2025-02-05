use strict;
use warnings;
use File::Basename;
use File::Path qw(make_path);
use Text::CSV;

# Input and output file paths
my $input_file_path = 'C:/PerfomanceTesting/Learning/LR2JMX/03.Scripts/DemoBlaze/CodeGenerationLog.txt';
my $output_directory = 'C:/PerfomanceTesting/Learning/LR2JMX/03.Scripts/DemoBlaze/Record';

# Regular expressions
my $transaction_start_regex = qr/\*{5} Request Header For Transaction With Id (\d+) \*{5}/;
my $host_fetcher_regex = qr/Host:\s+([^\s]+)/;

# Data structures to store transaction data
my %transaction_host_map;
my @transaction_ids;
my $current_transaction_id;
my $transaction_data = '';

# Open the input file
open my $reader, '<', $input_file_path or die "Cannot open file $input_file_path: $!\n";

# Ensure the output directory exists
make_path($output_directory) unless -d $output_directory;

# Read the file line by line
while (my $line = <$reader>) {
    chomp $line;

    # Check for a new transaction start
    if ($line =~ $transaction_start_regex) {
        # Save the previous transaction (if any) to a file
        if (defined $current_transaction_id && $transaction_data ne '') {
            write_transaction_to_file($output_directory, $current_transaction_id, $transaction_data);
        }

        # Start a new transaction
        $current_transaction_id = $1;
        push @transaction_ids, $current_transaction_id;
        $transaction_data = ''; # Reset transaction data for the new transaction
    }

    # Extract host information
    if ($line =~ $host_fetcher_regex) {
        my $host = $1;
        $transaction_host_map{$current_transaction_id} = $host;
    }

    # Append the current line to the transaction data
    if (defined $current_transaction_id) {
        $transaction_data .= $line . "\n";
    }
}

# Save the last transaction (if any)
if (defined $current_transaction_id && $transaction_data ne '') {
    write_transaction_to_file($output_directory, $current_transaction_id, $transaction_data);
}

# Write the transaction IDs and their respective hosts to a CSV file
write_transaction_ids_with_host_to_csv($output_directory, \@transaction_ids, \%transaction_host_map);

print "Transaction data segregated successfully into the 'output' directory.\n";
print "Transaction ID list with hosts saved as 'TransactionListWithHost.csv'.\n";

close $reader;

# Subroutine to write transaction data to a file
sub write_transaction_to_file {
    my ($output_directory, $transaction_id, $data) = @_;

    my $output_file_path = "$output_directory/Transaction_$transaction_id.txt";
    open my $writer, '>', $output_file_path or die "Cannot open file $output_file_path: $!\n";
    print $writer $data;
    close $writer;
}

# Subroutine to write transaction IDs and their associated hosts to a CSV file
sub write_transaction_ids_with_host_to_csv {
    my ($output_directory, $transaction_ids, $transaction_host_map) = @_;

    my $csv_file_path = "$output_directory/TransactionListWithHost.csv";
    open my $csv_fh, '>', $csv_file_path or die "Cannot open file $csv_file_path: $!\n";

    my $csv = Text::CSV->new({ binary => 1, eol => "\n" });
    $csv->say($csv_fh, ['Transaction ID', 'Host']);  # Write header

    foreach my $transaction_id (@$transaction_ids) {
        my $host = $transaction_host_map->{$transaction_id} // 'N/A';
        $csv->say($csv_fh, [$transaction_id, $host]);
    }

    close $csv_fh;
}
