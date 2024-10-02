@echo off
echo *******************************
echo ***** Running application *****
echo *******************************
set "CURRENT_SCRIPT_DIR=%~dp0"
set "CONFIG=Debug"
set "EXECUTABLE=%CURRENT_SCRIPT_DIR%build\%CONFIG%\force_me_to_learn.exe"

if not exist "%EXECUTABLE%" (
	echo Executable was not found at path: "%EXECUTABLE%"
	exit /b 1
)

"%EXECUTABLE%"

exit /B %ERRORLEVEL%
