cd .

if "%1"=="" (C:\PROGRA~1\MATLAB\R2016a\bin\win64\gmake -f BeschleunigungsAuswertung.mk all) else (C:\PROGRA~1\MATLAB\R2016a\bin\win64\gmake -f BeschleunigungsAuswertung.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make