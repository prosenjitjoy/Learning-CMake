cmake_minimum_required(VERSION 3.30)

project(targets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(terminal_app terminal.cpp)
add_executable(gui_app gui.cpp)

add_library(calculations calculations.h calculations.cpp)
add_library(drawing drawing.h drawing.cpp)

add_custom_target(checksum ALL
    COMMAND sh -c "cksum terminal_app>terminal.ck"
    COMMAND sh -c "cksum gui_app>gui.ck"
    BYPRODUCTS terminal.ck gui.ck
    COMMENT "Checking the sums..."
)

target_link_libraries(terminal_app calculations)
target_link_libraries(gui_app calculations drawing)

add_dependencies(checksum terminal_app gui_app)
