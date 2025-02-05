#!/usr/bin/perl
use strict;
use warnings;

# Check if the file is passed as a command-line argument
if (@ARGV != 1) {
    die "Usage: perl count_words.pl <filename>\n";
}

my $filename = $ARGV[0];

# Open the file for reading
open my $fh, '<', $filename or die "Cannot open file '$filename': $!\n";

my $word_count = 0;

# Read through the file and count the words
while (my $line = <$fh>) {
    chomp $line;
    my @words = split(/\s+/, $line);  # Split line into words based on whitespace
    $word_count += scalar @words;
}

# Close the file
close $fh;

# Print the word count
print "The file '$filename' contains $word_count words.\n";
