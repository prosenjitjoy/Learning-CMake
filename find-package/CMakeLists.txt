cmake_minimum_required(VERSION 3.30)

project(find-package LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(find-package main.cpp)

find_package(Calc REQUIRED)
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("CALC_FOUND: ${Calc_FOUND}")

include(CMakePrintHelpers)
cmake_print_properties(TARGETS "Calc::calc" PROPERTIES
    IMPORTED_CONFIGURATIONS
    INTERFACE_INCLUDE_DIRECTORIES
)
