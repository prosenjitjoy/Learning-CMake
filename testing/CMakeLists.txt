cmake_minimum_required(VERSION 3.30)

project(testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(program program.cpp)

add_executable(main main.cpp)
target_link_libraries(main program)

add_executable(test test.cpp)
target_link_libraries(test program)
