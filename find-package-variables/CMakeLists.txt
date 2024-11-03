cmake_minimum_required(VERSION 3.30)

project(find-package-variables LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(GENERATED_SRC GENERATED_HEADER message.proto)

add_executable(find-package-variables main.cpp ${GENERATED_SRC} ${GENERATED_HEADER})

target_link_libraries(find-package-variables PRIVATE
    ${Protobuf_LIBRARIES}
    ${Protobuf_PROTOC_LIBRARIES}
)
target_include_directories(find-package-variables PRIVATE
    ${Protobuf_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

include(GNUInstallDirs)
install(TARGETS find-package-variables
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
