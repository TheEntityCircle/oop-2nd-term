# требование нужной версии самого cmake
cmake_minimum_required(VERSION 3.1)

# как мы называемся
project(animals)

# требования к компилятору
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# опции при компиляции

# общие 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# для сборки c -DCMAKE_BUILD_TYPE=Debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
# для сборки с -DCMAKE_BUILD_TYPE=Release
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

file(GLOB SOURCES "*.cpp")

add_executable(animals ${SOURCES})
