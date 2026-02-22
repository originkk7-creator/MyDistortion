@echo off
echo ========================================
echo  GitHub Actions - Пуш кода
echo ========================================
echo.
echo 1. Создай репозиторий на GitHub:
echo    https://github.com/new
echo    Название: MyDistortion
echo    Public
echo.
echo 2. Введи URL репозитория ниже:
echo    (например: https://github.com/username/MyDistortion.git)
echo.
set /p REPO_URL="URL репозитория: "

if "%REPO_URL%"=="" (
    echo.
    echo Пустой URL!
    pause
    exit /b 1
)

echo.
echo Инициализация Git...
git init
git config user.name "YourName"
git config user.email "your@email.com"

echo.
echo Добавление файлов...
git add .
git commit -m "Initial commit - MyDistortion VST3"

echo.
echo Переименование ветки...
git branch -M main

echo.
echo Подключение репозитория...
git remote add origin %REPO_URL%

echo.
echo Пуш на GitHub...
git push -u origin main

echo.
echo ========================================
echo  ГОТОВО!
echo ========================================
echo.
echo Теперь:
echo 1. Зайди в свой репозиторий на GitHub
echo 2. Перейди во вкладку Actions
echo 3. Нажми Run workflow
echo 4. Жди сборку ~10 минут
echo.
pause
