cmake_minimum_required(VERSION 2.8)

project(animals)

file(GLOB SOURCES "*.cpp")

add_executable(animals ${SOURCES})
