cmake_minimum_required(VERSION 3.30)

project(configure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(configure main.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Doing things the usual way. ${CMAKE_SYSTEM_VERSION}")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Thinking differently")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "I'm supported here too")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking")
endif()

message(${CMAKE_HOST_SYSTEM_PROCESSOR})
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "Target is 64 bits")
endif()

message(${CMAKE_CXX_BYTE_ORDER})

include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ${ipo_supported})
message(${CMAKE_INTERPROCEDURAL_OPTIMIZATION})


list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_variable_templates result)
if(result EQUAL -1)
    message(FATAL_ERROR "Variable templates are required for compilation")
endif()

try_run(run_result compile_result
        ${CMAKE_BINARY_DIR}/test_output ${CMAKE_SOURCE_DIR}/main.cpp
        RUN_OUTPUT_VARIABLE output)

message("run_result: ${run_result}")
message("compile_result: ${compile_result}")
message("output:\n\n${output}")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed")
endif()
message("Build successfull!")

include(GNUInstallDirs)
install(TARGETS configure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
