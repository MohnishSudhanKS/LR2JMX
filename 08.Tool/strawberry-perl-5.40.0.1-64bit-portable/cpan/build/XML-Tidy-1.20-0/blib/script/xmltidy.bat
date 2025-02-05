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
#!/usr/bin/perl
#line 16
# 4BJJ9OVI:xmltidy created by Pip Stuart <Pip@CPAN.Org>
#   to tidy up all the element indenting of XML documents.
# The accepted parameters to this script are:
#   filename       (presumably an XML file with misaligned elements)
#   indent_string  ('tab' works as an alternate way to specify "\t")
# Examples:                        # two  (2) spaces is default
#   `xmltidy FileName.xml ' '   `  # one  (1) space  per indent level
#   `xmltidy FileName.xml '    '`  # four (4) spaces per indent level
#   `xmltidy FileName.xml tab   `  # one  (1) tab    per indent level
# This utility is part of the XML::Tidy Perl Module. Please run
#   `perldoc XML::Tidy` from the command-line for further documentation.
# This code is licensed under the GNU General Public License version 3+.
use strict;use warnings;use XML::Tidy;
my $flnm = shift() || die "USAGE: `$0 FileName.xml '<indent_string>'`\n";
my $nxto = XML::Tidy->new($flnm);$nxto->tidy(shift());$nxto->write();
__END__
:endofperl
@set "ErrorLevel=" & @goto _undefined_label_ 2>NUL || @"%COMSPEC%" /d/c @exit %ErrorLevel%
