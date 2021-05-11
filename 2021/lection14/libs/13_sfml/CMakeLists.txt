cmake_minimum_required(VERSION 2.8)
  
project(sfmltest)
add_executable(sfmltest main.cpp)

# Найдём SFML
find_package(SFML REQUIRED)

# Теперь можно выставить директории с header-ами
include_directories(${SFML_INCLUDE_DIR})

# И указать библиотеки для линковки
target_link_libraries(sfmltest sfml-graphics sfml-window sfml-system)
