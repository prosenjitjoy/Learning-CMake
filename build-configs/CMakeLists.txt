cmake_minimum_required(VERSION 3.30)

project(build-configs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(build-configs main.cpp)

include(GNUInstallDirs)
install(TARGETS build-configs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
