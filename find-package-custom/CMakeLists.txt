cmake_minimum_required(VERSION 3.30)

project(find-package-custom LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/module/")
find_package(PQXX REQUIRED)

message("FOUND: " ${PQXX_FOUND})

add_executable(find-package-custom main.cpp)
target_link_libraries(find-package-custom PRIVATE PQXX::PQXX)
