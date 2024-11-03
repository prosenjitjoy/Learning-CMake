cmake_minimum_required(VERSION 3.30)

project(ctest-catch2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
add_subdirectory(src bin)
add_subdirectory(test)
