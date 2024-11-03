cmake_minimum_required(VERSION 3.30)

project(unresolved LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(outer outer.cpp)
add_library(nested nested.cpp)

add_executable(unresolved main.cpp)
target_link_libraries(unresolved outer nested)

include(GNUInstallDirs)
install(TARGETS unresolved
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
