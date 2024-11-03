cmake_minimum_required(VERSION 3.30)

project(libraries LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(my_static STATIC function_a.cpp function_b.cpp)
add_library(my_shared SHARED function_a.cpp function_b.cpp)
add_library(my_module MODULE function_a.cpp function_b.cpp)

add_executable(libraries main.cpp)

include(GNUInstallDirs)
install(TARGETS libraries
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
