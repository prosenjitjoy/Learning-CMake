cmake_minimum_required(VERSION 3.30)

project(cxx-modules LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(math)
target_sources(math PUBLIC
    FILE_SET CXX_MODULES
    FILES math.cxx
)

add_executable(cxx-modules main.cxx)
target_link_libraries(cxx-modules PRIVATE math)
