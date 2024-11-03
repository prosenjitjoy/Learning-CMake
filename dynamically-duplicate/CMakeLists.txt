cmake_minimum_required(VERSION 3.30)

project(dynamically-duplicate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(a SHARED a.cpp)
add_library(b SHARED b.cpp)

add_executable(main1 main.cpp)
target_link_libraries(main1 a b)

add_executable(main2 main.cpp)
target_link_libraries(main2 b a)
