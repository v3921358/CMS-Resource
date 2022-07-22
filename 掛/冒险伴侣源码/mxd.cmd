@ECHO OFF
if exist *.positions del /f /q *.positions 1>nul 2>nul
if exist *.ncb del /f /q *.ncb 1>nul 2>nul
if exist *.plg del /f /q *.plg 1>nul 2>nul
if exist *.opt del /f /q *.opt 1>nul 2>nul
if exist *.aps del /f /q *.aps 1>nul 2>nul
if exist Release rd /s /q Release 1>nul 2>nul
if exist Debug rd /s /q Debug 1>nul 2>nul