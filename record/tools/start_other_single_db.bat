@echo off

start /min DB_Server start
IF %ERRORLEVEL% LEQ 1 echo DB_Server
start /min Sel_Char_Server start
IF %ERRORLEVEL% LEQ 1 echo Sel_Char_Server
start /min Game_Server start
IF %ERRORLEVEL% LEQ 1 echo Game_Server
start /min Secu_Server start
IF %ERRORLEVEL% LEQ 1 echo Secu_Server