add_library(calc_tui_static STATIC tui.cpp)
target_sources(calc_tui_static
    PUBLIC FILE_SET HEADERS BASE_DIRS include
    FILES include/tui.h
)
target_precompile_headers(calc_tui_static PUBLIC <string>)

include(GetFTXUI)
target_link_libraries(calc_tui_static PUBLIC calc_shared ftxui::screen ftxui::dom ftxui::component)

include(BuildInfo)
BuildInfo(calc_tui_static)

AddForCoverage(calc_tui_static)
CleanCoverage(calc_tui_static)

Format(calc_tui_static .)

AddCppCheck(calc_tui_static)

Doxygen(calc_tui src/calc_tui)

add_executable(calc_tui bootstrap.cpp)
target_link_libraries(calc_tui calc_tui_static)

include(GNUInstallDirs)
install(TARGETS calc_tui
    RUNTIME COMPONENT runtime
)
