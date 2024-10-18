cmake_minimum_required(VERSION 3.30)

project(properties LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(source1 main.cpp)
set_property(TARGET source1 PROPERTY INTERFACE_LIB_VERSION 4)
set_property(TARGET source1 APPEND PROPERTY COMPATIBLE_INTERFACE_STRING LIB_VERSION)

add_library(source2 main.cpp)
set_property(TARGET source2 PROPERTY INTERFACE_LIB_VERSION 4)

add_library(destination main.cpp)
target_link_libraries(destination source1 source2)

add_executable(properties main.cpp)

include(GNUInstallDirs)
install(TARGETS properties
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
