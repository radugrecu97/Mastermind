# abstract classes
add_library(peg_manager_abs INTERFACE)

target_include_directories(peg_manager_abs
        INTERFACE
        .
        )

target_link_libraries(peg_manager_abs INTERFACE)