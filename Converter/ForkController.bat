@echo off
setlocal

:: Set the name of the Unreal Engine process
set "UE_PROCESS=UnrealEditor.exe"

:: Check if Unreal Engine process is running
tasklist /FI "IMAGENAME eq %UE_PROCESS%" 2>NUL | find /I /N "%UE_PROCESS%">NUL
if "%ERRORLEVEL%"=="0" (
    :: Unreal Engine is running, display an error message
    echo Unreal Engine is currently running. Please close it before opening Fork.
    pause
    exit /B 1
) else (
    :: Unreal Engine is not running, start Fork
    echo Starting Fork...
    start "" "C:\Users\robin\AppData\Local\Fork\Fork.exe"
)

endlocal



ALT + C = Alle Triangles anzeigen im Editor

Set Timer by function Name -> clear Timer by function name