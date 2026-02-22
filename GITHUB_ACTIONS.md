# 🚀 GitHub Actions — Сборка VST3

## Как использовать:

### 1. Создай репозиторий на GitHub
- https://github.com/new
- Название: `MyDistortion`
- Public

### 2. Запуш код
```bash
cd C:\Users\Dexter\Desktop\Vstcreator\MyDistortion
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/ТВОЙ_НИК/MyDistortion.git
git push -u origin main
```

### 3. Запусти сборку
- Зайди в репозиторий на GitHub
- Перейди в **Actions** → **Build VST3**
- Нажми **Run workflow**
- Жди ~10-15 минут

### 4. Скачай VST3
- После завершения открой артефакт
- Скачай `MyDistortion-VST3-Windows.zip`
- Распакуй в папку VST3 твоей DAW

## 📦 Артефакты
Сборка создаёт 3 файла:
- **Windows**: `MyDistortion.vst3`
- **Linux**: `MyDistortion.vst3`
- **macOS**: `MyDistortion.vst3`
