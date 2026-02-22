@echo off
echo ========================================
echo  MyDistortion - Push to GitHub
echo  User: originkk7
echo ========================================
echo.

cd /d "%~dp0"

echo Инициализация Git...
git init
git config user.name "originkk7"
git config user.email "originkk7@users.noreply.github.com"

echo.
echo Добавление файлов...
git add .
git commit -m "Initial commit - MyDistortion VST3"

echo.
echo Переименование ветки...
git branch -M main

echo.
echo Подключение репозитория...
git remote remove origin 2>nul
git remote add origin https://github.com/originkk7/MyDistortion.git

echo.
echo Пуш на GitHub...
git push -u origin main

if errorlevel 1 (
    echo.
    echo ========================================
    echo  ОШИБКА!
    echo ========================================
    echo.
    echo Возможные причины:
    echo 1. Репозиторий не создан на GitHub
    echo 2. Неверное имя пользователя
    echo.
    echo Создай репозиторий:
    echo https://github.com/new
    echo Название: MyDistortion
    echo Public
    echo.
) else (
    echo.
    echo ========================================
    echo  УСПЕХ!
    echo ========================================
    echo.
    echo Код загружен в:
    echo https://github.com/originkk7/MyDistortion
    echo.
    echo Далее:
    echo 1. Открой https://github.com/originkk7/MyDistortion/actions
    echo 2. Нажми Run workflow
    echo 3. Жди сборку ~10-15 минут
    echo.
)

pause
