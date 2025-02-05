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
#!C:\PerfomanceTesting\Learning\LR2JMX\08.Tool\strawberry-perl-5.40.0.1-64bit-portable\perl\bin\perl.exe 
#line 16
# 315JEHVb:cnv (CoNVert number bases) <NumberString> <FromBase> <ToBase> created by Pip Stuart <Pip@CPAN.Org> as part of the Math::BaseCnv package.
#   If you only supply a number, it will convert to HEX if it's decimal and decimal if it contains only valid HEX digits. If you just provide one
#     base parameter, it assumes that your number is already base10 and that you've supplied the ToBase. Otherwise, you need from and to parameters.
# Examples: `cnv 127   10 16` ==    "7F"
#           `cnv 7F    16  3` == "11201"
#           `cnv 11201  3  7` ==   "241"
#           `cnv 241    7 10` ==   "127"    # Eror checking is minimal.
use strict;use warnings;use utf8;use Math::BaseCnv;
my $numb=shift;die("USAGE: `cnv <NumberString> <FromBase> <ToBase>`\n") if(!defined($numb) || $numb =~ /^-+[h\?]/i);print(cnv($numb,shift,shift));
__END__
:endofperl
@set "ErrorLevel=" & @goto _undefined_label_ 2>NUL || @"%COMSPEC%" /d/c @exit %ErrorLevel%
