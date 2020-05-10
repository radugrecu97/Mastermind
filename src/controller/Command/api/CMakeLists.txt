add_library(command_api INTERFACE)

target_include_directories(command_api
        INTERFACE
        .
        )

target_link_libraries(command_api INTERFACE)