@echo off
REM ===========================================================================
REM pmake - Build wrapper for 1st Engine
REM ===========================================================================
REM This script invokes mingw32-make (GNU Make from MSYS2 UCRT64) using
REM 'pmakefile' as the build configuration file.
REM
REM Usage:
REM   pmake          - Build the project
REM   pmake build    - Build the project
REM   pmake run      - Build and run
REM   pmake clean    - Remove build artifacts
REM   pmake rebuild  - Clean and rebuild
REM ===========================================================================

set PATH=C:\msys64\ucrt64\bin;%PATH%

if "%1"=="clean" (
    mingw32-make -f pmakefile clean
    pause
    exit /b
)

if "%1"=="rebuild" (
    mingw32-make -f pmakefile rebuild
) else (
    mingw32-make -f pmakefile build
)

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    pause
    exit /b
)

echo.
echo [RUN] Launching engine.exe directly...
build\engine.exe
pause