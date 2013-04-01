@echo off

set range=4

for /L %%i in (1, 1, %range%) do (
copy /Y DB_Server* .\db%%i
copy /Y *.dll .\db%%i
copy /Y *.manifest .\db%%i
)

start /min DB_Server start
IF %ERRORLEVEL% LEQ 1 echo DB_Server
ping 127.0.0.1 -n 3 > nul
cd ./db1

for /L %%i in (1, 1, %range%) do (
cd ../db%%i
start /min DB_Server start
IF %ERRORLEVEL% LEQ 1 echo DB_Server
ping 127.0.0.1 -n 3 > nul
)

cd ..
start /min Sel_Char_Server start
IF %ERRORLEVEL% LEQ 1 echo Sel_Char_Server
start /min Game_Server start
IF %ERRORLEVEL% LEQ 1 echo Game_Server
start /min Secu_Server start
IF %ERRORLEVEL% LEQ 1 echo Secu_Server