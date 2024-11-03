cmake_minimum_required(VERSION 3.30)

project(one-definition-rule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(one-definition-rule
    one.cpp
    shared.h
    two.cpp)

include(GNUInstallDirs)
install(TARGETS one-definition-rule
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
