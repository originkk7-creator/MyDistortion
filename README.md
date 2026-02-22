# MyDistortion - VST3 на iPlug2

## 📁 Структура
```
MyDistortion/
├── MyDistortion.h/cpp    # Код плагина
├── config.h              # Настройки
├── parameters.h          # Параметры
├── CMakeLists.txt        # Сборка
├── Resources/
│   └── back.png          # Фон
└── ../iPlug2/            # Фреймворк
```

## 🚀 Сборка

### Требуется
- Visual Studio 2022 (или Build Tools)
- CMake 3.20+

### Команды
```bash
cd C:\Users\Dexter\Desktop\Vstcreator\MyDistortion
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

### Где VST3
`build/Release/MyDistortion.vst3`

## 🎛️ Параметры
- **Drive** — сила дисторшна
- **Tone** — фильтр
- **Mix** — dry/wet
