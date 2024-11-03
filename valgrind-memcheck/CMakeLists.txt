cmake_minimum_required(VERSION 3.30)

project(valgrind-memcheck LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(CTest)
add_subdirectory(src bin)
add_subdirectory(test)
