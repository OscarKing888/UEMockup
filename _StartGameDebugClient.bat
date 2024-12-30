setlocal enabledelayedexpansion
 
call _SetEngineDir.bat %1
@echo on
"%EngineDir%\Binaries\Win64\%EngineExe%" "%prj%" 127.0.0.1 %GameParams% -debug

if "%PauseCmd%"=="" (
    timeout /t 5 >nul
) else (
    pause
)


endlocal
