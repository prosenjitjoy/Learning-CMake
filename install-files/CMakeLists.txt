cmake_minimum_required(VERSION 3.30)

project(install-files LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
install(FILES
    src/include/calc/basic.h
    src/include/calc/nested/extended.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/calc
)
