cmake_minimum_required(VERSION 3.30)

project(external-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(external-project main.cpp)
configure_file(config.yaml config.yaml COPYONLY)

configure_file(yaml-cpp.in yaml-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/yaml-download"
)

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/yaml-download"
)

add_subdirectory("${CMAKE_BINARY_DIR}/yaml-cpp-src" "${CMAKE_BINARY_DIR}/yaml-cpp-build")
target_link_libraries(external-project PRIVATE yaml-cpp::yaml-cpp)
