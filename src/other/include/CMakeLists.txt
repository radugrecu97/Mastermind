add_library(constants INTERFACE)

target_include_directories(constants
        INTERFACE
        .
        )

target_link_libraries(constants INTERFACE)