cmake_minimum_required(VERSION 3.30)

project(custom-command LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(custom-command main.cpp constants.h)
target_include_directories(custom-command PRIVATE ${CMAKE_BINARY_DIR})
add_custom_command(
    OUTPUT constants.h
    COMMAND cp ARGS "${CMAKE_SOURCE_DIR}/template.xyz" constants.h
)

add_custom_command(
    TARGET custom-command POST_BUILD
    COMMAND cksum ARGS "$<TARGET_FILE:custom-command>" > "main.ck"
)
