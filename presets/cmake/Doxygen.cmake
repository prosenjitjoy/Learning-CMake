function(Doxygen target input)
    find_package(Doxygen REQUIRED)

    set(DOCS_DIR "${PROJECT_BINARY_DIR}/docs")
    file(MAKE_DIRECTORY ${DOCS_DIR})

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT "${DOCS_DIR}/${target}")

    doxygen_add_docs("doxygen-${target}"
        ${PROJECT_SOURCE_DIR}/${input}
        COMMENT "Generate HTML documentation"
    )
endfunction()
