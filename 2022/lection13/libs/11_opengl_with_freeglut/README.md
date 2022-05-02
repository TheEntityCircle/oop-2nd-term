Это базовый пример, на котором можно проверить, в норме ли окружение.

Здесь предполагается OpenGL + FreeGLUT и сборка средствами CMake.

### Материалы по собственно OpenGL (что и как писать дальше)
- Туториалы на русском (перевод) - https://triplepointfive.github.io/ogltutor/
- Туториалы на английском (оригинал) - http://ogldev.atspace.co.uk/

### Краткая памятка для Linux
- Поставить библиотеки и заголовочные файлы:
```
yum install freeglut freeglut-devel (или аналог на другом дистрибутиве)
```
- Собраться
```
mkdir build
cd build
cmake ..
make
```

### Быстрая и грязная инструкция для 32-х битной Windows c MinGW
- Скачать бинарники FreeGLUT под MinGW - https://www.transmissionzero.co.uk/software/freeglut-devel/
- Распаковать их, freeglut.dll из папки bin скопировать в "C:\Windows\System32", содержимое папок include и lib скопировать в "MinGW\include" и "MinGW\lib"
- Собраться
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```
