cmake_minimum_required(VERSION 3.30)

project(version-file
    VERSION 1.2.3
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src bin)
