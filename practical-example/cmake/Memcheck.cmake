function(AddMemcheck target)
    find_program(VALGRIND_PATH valgrind REQUIRED)
    add_custom_target(memcheck-${target}
        COMMAND ${VALGRIND_PATH} --leak-check=yes $<TARGET_FILE:${target}>
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endfunction()
