cmake_minimum_required(VERSION 3.30)

project(rental LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rental main.cpp)
add_subdirectory(cars)
target_link_libraries(rental PRIVATE cars)

include(GNUInstallDirs)
install(TARGETS rental
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
