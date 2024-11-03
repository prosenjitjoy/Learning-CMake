cmake_minimum_required(VERSION 3.30)

project(doxygen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(src bin)

include(Doxygen)
Doxygen(src docs)
