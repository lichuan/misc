@echo off
start /min Center_Server start
IF %ERRORLEVEL% LEQ 1 echo Center_Server
start /min Web_DB_Server start
IF %ERRORLEVEL% LEQ 1 echo Web_DB_Server
start /min Login_Server start
IF %ERRORLEVEL% LEQ 1 echo Login_Server
