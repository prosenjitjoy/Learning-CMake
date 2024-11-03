cmake_minimum_required(VERSION 3.30)

project(fetch-content-find-package LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fetch-content-find-package main.cpp)
configure_file(config.yaml config.yaml COPYONLY)

include(FetchContent)
FetchContent_Declare(external-yaml-cpp
    GIT_REPOSITORY  https://github.com/jbeder/yaml-cpp.git
    GIT_TAG 0.8.0
    FIND_PACKAGE_ARGS NAMES yaml-cpp
)

FetchContent_MakeAvailable(external-yaml-cpp)
target_link_libraries(fetch-content-find-package PRIVATE yaml-cpp::yaml-cpp)

include(CMakePrintHelpers)
cmake_print_properties(TARGETS yaml-cpp::yaml-cpp
    PROPERTIES TYPE
    SOURCE_DIR INTERFACE_INCLUDE_DIRECTORIES
)
