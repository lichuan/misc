@echo off
for %%i in (Secu_Server.exe Login_Server.exe Sel_Char_Server.exe Game_Server.exe DB_Server.exe Center_Server.exe Web_DB_Server.exe) do taskkill /f /im %%i