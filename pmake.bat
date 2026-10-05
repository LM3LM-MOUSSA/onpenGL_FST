@echo off
REM ===========================================================================
REM pmake - Build wrapper - MSVC v145 / Visual Studio 2026
REM ===========================================================================

REM Charger l'environnement MSVC x64 avec le toolset v145
call "C:\Program Files\Microsoft Visual Studio\18\Insiders\VC\Auxiliary\Build\vcvars64.bat"

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Impossible de charger MSVC v145.
    pause
    exit /b 1
)

echo.
echo [INFO] Compiler:
where cl
cl

echo.
echo [INFO] Building...

if "%1"=="clean" (
    nmake /F pmakefile clean
    pause
    exit /b
)

if "%1"=="rebuild" (
    nmake /F pmakefile rebuild
) else (
    nmake /F pmakefile build
)

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Build failed!
    pause
    exit /b 1
)

echo.
echo [RUN] Launching engine.exe...
build\engine.exe

pause