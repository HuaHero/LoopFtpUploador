@Echo Off
 rem Echo %1
 Echo open 127.0.0.1 21 >ftp.up
 Echo admin>>ftp.up
 Echo admin123>>ftp.up
 Echo lcd .>>ftp.up
 Echo Cd .\ >>ftp.up
 rem Echo binary>>ftp.up
 for /F "tokens=1 delims=_" %%a in ("%1") do (set acount=%%a)
 Echo mkdir .\%acount%>>ftp.up
 Echo Cd .\%acount%>>ftp.up
 for /F "tokens=3 delims=_" %%f in ("%1") do (set datedir=%%f)
 set datedir=%datedir:~0,8%
 for /F "tokens=1-3 delims=/ " %%m in ('date /t') do (set curdate=%%m%%n%%o) 
 rem echo %curdate%>>ftp.up
 rem echo %datedir%>>ftp.up
 if	"%datedir%" == "%curdate%" (exit)
 set datedir=%datedir:~0,6%
 rem Echo %datedir%>>ftp.up
 Echo mkdir .\%datedir%>>ftp.up
 Echo Cd .\%datedir%>>ftp.up
 Echo put %1>>ftp.up
 Echo bye>>ftp.up
 FTP -s:ftp.up
 rem timeout /t 30 >nul
 del ftp.up /q
 del /f %1
 pause
