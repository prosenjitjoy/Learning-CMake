cmake_minimum_required(VERSION 3.30)

project(definitions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(undefined main.cpp)

set(VAR 8)
add_executable(defined main.cpp)
target_compile_definitions(defined PRIVATE ABC "DEF=${VAR}")

add_executable(configure configure.cpp)
set(FOO_ENABLE ON)
set(FOO_STRING1 "abc")
set(FOO_STRING2 "def")
configure_file(configure.txt configured/configure.h)
target_include_directories(configure PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
