@echo off
chcp 65001
echo/-- строка параметров: %* 
echo/-- параметр 1: %1 
echo/-- параметр 2: %2 
echo/-- параметр 3: %3 


SET /A c = %1 + %2 
SET /A d = %1 * %2 
SET /A e = %3 / %2 
SET /A f = %2 - %1 
SET /A g = (%2 - %1)*(%1-%2) 
echo %1 + %2 = %c%
echo %1 * %2 = %d%
echo %3 / %2 = %e%
echo %2 - %1 = %f%
echo (%2 - %1)*(%1 - %2) = %g%