@echo off
echo ********************************
echo ***** Build.cmd is running *****
echo ********************************
set "CURRENT_SCRIPT_DIR=%~dp0"
set "BUILD_FOLDER=%CURRENT_SCRIPT_DIR%\build"
set "SRC_FOLDER=%CURRENT_SCRIPT_DIR%\src"
set "CONFIG=Debug"

if exist "%BUILD_FOLDER%" (
	echo Recreating build folder
	rmdir /S /Q "%BUILD_FOLDER%"
)

mkdir "%BUILD_FOLDER%"
PUSHD "%BUILD_FOLDER%"

echo Building project in configuration %CONFIG%...
cmake "%SRC_FOLDER%"
cmake --build "%BUILD_FOLDER%" --config %CONFIG%

POPD

exit /B 0
