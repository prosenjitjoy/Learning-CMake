cmake_minimum_required(VERSION 3.30)

project(sources LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sources main.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(sources PRIVATE gui_linux.cpp)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_sources(sources PRIVATE gui_windows.cpp)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_sources(sources PRIVATE gui_darwin.cpp)
else()
    message(FATAL_ERROR "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME} not supported.")
endif()

include(GNUInstallDirs)
install(TARGETS sources
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
