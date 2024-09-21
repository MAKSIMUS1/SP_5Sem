@echo off
chcp 65001

echo/-- строка параметров : %1 %2
echo/-- режим: %1
echo/-- имя файла: %2

if "%1" equ "" (
    if "%2" equ "" ( 
        goto reference
    )
)

if "%2" equ "" (
    if "%1" neq "" (
        goto no_second_param
    )
)

if "%2" neq "" (
    if "%1" neq "создать" (
        if "%1" neq "удалить" (
            goto bad_first_param
        )
    )
)
if exist %2 (
    if "%1" equ "создать" (
        echo/---+ файл %2 уже есть
        goto end
    )
)
if exist %2 (
    if "%1" equ "удалить" (
        del %2
        echo/---+ файл %2 удален
        goto end
    )
)

if not exist %2 (
    goto not_exist_file
)



goto unexpected_error

:reference
echo/---+ %~nx0 режим файла
echo/---++ режим = {создать, удалить}
echo/---++ файл = имя файла
goto end

:no_second_param
echo/---+ не задано имя файла
goto end

:bad_first_param
echo/---+ режим задан не корректно
goto end

:not_exist_file
if "%1" equ "создать" (
    copy nul "%2"
) else (
    echo/---+ файл %2 не найден
)
if "%1" equ "удалить" (
    del %2
) else (
    echo/---+ файл %2 не найден
)
goto end


:unexpected_error
echo/---+ unexpected_error
goto end

:end
pause