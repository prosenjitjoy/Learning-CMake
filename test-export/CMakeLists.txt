cmake_minimum_required(VERSION 3.30)

project(test-export LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("/home/prosenjit/Code/target-export/build/Desktop-Debug/cmake/CalcTargets.cmake")

include(CMakePrintHelpers)
cmake_print_properties(TARGETS "Calc::calc" PROPERTIES
    IMPORTED_CONFIGURATIONS
    INTERFACE_INCLUDE_DIRECTORIES
)

add_executable(test-export main.cpp)
target_link_libraries(test-export PRIVATE Calc::calc)
