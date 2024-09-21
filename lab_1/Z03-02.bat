@echo off
chcp 65001
echo/-- имя этого bat-файла: %~nx0%
for /f "tokens=1-5 delims=.: " %%j in ('
 dir/a-d/tc "%sourcePath%"^| findstr/rc:"^[^ ]"
') do (
 set mydate=%%l.%%k.%%j
 set mytime=%%m-%%n
)
echo/-- этот bat-файл создан: %mydate% %mytime%
echo/-- путь bat-файла: %~dp0%
