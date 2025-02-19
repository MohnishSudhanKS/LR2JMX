@rem = '--*-Perl-*--
@set "ErrorLevel="
@if "%OS%" == "Windows_NT" @goto WinNT
@perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
@set ErrorLevel=%ErrorLevel%
@goto endofperl
:WinNT
@perl -x -S %0 %*
@set ErrorLevel=%ErrorLevel%
@if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" @goto endofperl
@if %ErrorLevel% == 9009 @echo You do not have Perl in your PATH.
@goto endofperl
@rem ';
#!/usr/bin/env perl
#line 16

use strict;
use warnings;
use XML::XPath;
use I18N::Langinfo qw/langinfo CODESET/;
use Encode qw/decode/;
use open ':std', ':locale';

$| = 1;

my $codeset = langinfo(CODESET);
if ($codeset ne "") {
    @ARGV = map { decode $codeset, $_ } @ARGV;
}

my $SUFFIX = "\n";
my $PREFIX = "";
my $quiet  = 0;

my @paths;
# TODO: Use Getopt::Long for parsing?
PARSE: while ((@ARGV >= 1) && ($ARGV[0] =~ /^-./ )) {
    OPTIONS: {
        if ($ARGV[0] eq "-e") {
            shift;
            push @paths, shift;
            last OPTIONS;
        }
        if ($ARGV[0] eq "-q") {
            $quiet = 1;
            shift;
            last OPTIONS;
        }
        if ($ARGV[0] eq "-p") {
            shift;
            $PREFIX = shift;
            last OPTIONS;
        }
        if ($ARGV[0] eq "-s") {
            shift;
            $SUFFIX = shift;
            last OPTIONS;
        }
        if ($ARGV[0] eq "-n") {
            $XML::XPath::ParseParamEnt = 0;
            shift;
            last OPTIONS;
        }
        print STDERR "Unknown option ignore: ", shift;
    }
}

unless (@paths >= 1) {
    print STDERR qq(Usage:
$0 [options] -e query [-e query...] [filename...]

If no filenames are given, supply XML on STDIN. You must provide at
least one query. Each supplementary query is done in order, the
previous query giving the context of the next one.

Options:

-q quiet, only output the resulting PATH.
-s suffix, use suffix instead of linefeed.
-p postfix, use prefix instead of nothing.
-n Don't use an external DTD.
);
    exit;
}

do {
    my ($xpath, $filename);
    my @curpaths = @paths;

    if (@ARGV >= 1) {
        $filename = shift @ARGV;
        $xpath    = XML::XPath->new(filename => $filename);
    }
    else {
        $filename = 'stdin';
        binmode STDIN, ':raw'; # Let the XML parser decode the input
	$xpath    = XML::XPath->new(ioref => \*STDIN);
    }

    my $nodes = $xpath->find(shift @curpaths);

    if ($nodes->isa('XML::XPath::NodeSet')) {
        while (@curpaths >= 1) {
            $nodes = find_more($xpath, shift @curpaths, $nodes);
            last unless $nodes->isa('XML::XPath::NodeSet');
        }
    }

    if ($nodes->isa('XML::XPath::NodeSet')) {
        if ($nodes->size) {
            print STDERR "Found ", $nodes->size, " nodes in $filename:\n" unless $quiet;
            foreach my $node ($nodes->get_nodelist) {
                print STDERR "-- NODE --\n" unless $quiet;
                print $PREFIX, $node->toString, $SUFFIX;
            }
        }
        else {
            print STDERR "No nodes found in $filename\n" unless $quiet;
        }
    }
    else {
        print STDERR "Query didn't return a nodeset. Value: " unless $quiet;
        print $nodes->value, "\n";
    }

} until (@ARGV < 1);

exit;

sub find_more {
    my $xpath   = shift;
    my $find    = shift;
    my ($nodes) = @_;

    my $newnodes = XML::XPath::NodeSet->new;

    foreach my $node ($nodes->get_nodelist) {
        my $new = $xpath->find($find, $node);
        if ($new->isa('XML::XPath::NodeSet')) {
            $newnodes->append($new);
        }
        else {
            warn "Not a nodeset: ", $new->value, "\n";
        }
    }

    return $newnodes;
}

__END__

=head1 NAME

xpath - a script to query XPath statements in XML documents.

=head1 SYNOPSIS

B<xpath [-s suffix] [-p prefix] [-n] [-q] -e query [-e query] ... [file] ...>

=head1 DESCRIPTION

B<xpath> uses the L<XML::XPath> perl module to make XPath queries to any XML document.
The L<XML::XPath|XML::XPath> module aims to comply exactly to the XPath specification
at C<http://www.w3.org/TR/xpath> and yet allows extensions to be added in the form of
functions.

The script takes any number of XPath pointers and tries to apply them to each XML document
given on the command line. If no file arguments are given, the query is done using C<STDIN>
as an XML document.

When multiple queries exist, the result of the last query is used as context for the next
query and only the result of the last one is output. The context of the first query is always
the root of the current document.

=head1 OPTIONS

=head2 B<-q>

Be quiet. Output only errors (and no separator) on stderr.

=head2 B<-n>

Never use an external DTD, ie. instantiate the XML::Parser module with 'ParseParamEnt => 0'.

=head2 B<-s suffix>

Place C<suffix> at the end of each entry. Default is a linefeed.

=head2 B<-p prefix>

Place C<prefix> preceding each entry. Default is nothing.

=head1 BUGS

The author of this man page is not very fluant in english. Please, send him (fabien@tzone.org)
any corrections concerning this text.

=head1 SEE ALSO

L<XML::XPath>

=head1 LICENSE AND COPYRIGHT

This module is  copyright  2000 AxKit.com Ltd. This is free software, and as such
comes with NO WARRANTY. No dates are used in this module. You may distribute this
module under the terms  of either the Gnu GPL,  or the Artistic License (the same
terms as Perl itself).

For support, please subscribe to the L<Perl-XML|http://listserv.activestate.com/mailman/listinfo/perl-xml>
mailing list at the URL

=cut
__END__
:endofperl
@set "ErrorLevel=" & @goto _undefined_label_ 2>NUL || @"%COMSPEC%" /d/c @exit %ErrorLevel%
