add_subdirectory(lib1)
add_subdirectory(lib2)
add_executable(structure main.cpp
    include/class_a.h include/class_a.cpp
    include/class_b.h include/class_b.cpp
)

target_include_directories(structure PRIVATE include)
target_link_libraries(structure PRIVATE lib1 lib2)
