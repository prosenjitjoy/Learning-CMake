function(Doxygen input output)
    find_package(Doxygen REQUIRED)

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT ${CMAKE_BINARY_DIR}/${output})

    doxygen_add_docs(doxygen
        ${CMAKE_SOURCE_DIR}/${input}
        COMMENT "Generate HTML documentation"
    )
endfunction()
