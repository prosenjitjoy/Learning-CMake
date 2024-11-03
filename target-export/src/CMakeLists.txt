add_library(calc STATIC calc.cpp)
target_sources(calc
    PUBLIC FILE_SET CXX_MODULES FILES extended.cxx
    PUBLIC FILE_SET HEADERS BASE_DIRS include
    FILES "include/calc/calc.h"
)

target_compile_features(calc PRIVATE cxx_std_23)
set_target_properties(calc PROPERTIES CXX_EXTENSIONS OFF)

export(TARGETS calc
    FILE "${CMAKE_BINARY_DIR}/cmake/CalcTargets.cmake"
    CXX_MODULES_DIRECTORY "modules"
    NAMESPACE Calc::
)

add_executable(main main.cpp)
