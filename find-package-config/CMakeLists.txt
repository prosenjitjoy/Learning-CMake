cmake_minimum_required(VERSION 3.30)

project(find-package-config LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED IMPORTED_TARGET libpqxx)
message("PQXX_FOUND: ${PQXX_FOUND}")

add_executable(find-package-config main.cpp)
target_link_libraries(find-package-config PkgConfig::PQXX)
