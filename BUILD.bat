@echo off
echo ========================================
echo  MyDistortion - Сборка VST3
echo ========================================
echo.

if not exist "build" mkdir build
cd build

echo Настройка CMake...
cmake .. -G "Visual Studio 17 2022" -A x64
if errorlevel 1 (
    echo.
    echo ОШИБКА: Visual Studio не найдена!
    echo Установи Visual Studio 2022 или Build Tools:
    echo https://visualstudio.microsoft.com/visual-cpp-build-tools/
    pause
    exit /b 1
)

echo.
echo Сборка...
cmake --build . --config Release

if exist "Release\MyDistortion.vst3" (
    echo.
    echo ========================================
    echo  УСПЕХ! VST3 создан:
    echo  %CD%\Release\MyDistortion.vst3
    echo ========================================
) else (
    echo.
    echo ОШИБКА сборки!
)

echo.
cd ..
pause
