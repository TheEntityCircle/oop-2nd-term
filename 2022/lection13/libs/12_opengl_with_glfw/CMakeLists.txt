cmake_minimum_required(VERSION 2.8)
  
project(glfwtest)
add_executable(glfwtest main.cpp)

# Найдём OpenGL
find_package(OpenGL REQUIRED)
# Найдём GLFW немного непрямым способом
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Теперь можно выставить директории с header-ами
include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

# И указать библиотеки для линковки
target_link_libraries(glfwtest ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
