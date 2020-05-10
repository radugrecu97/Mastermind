add_library(controller_api INTERFACE)

target_include_directories(controller_api
        INTERFACE
        .
        )

target_link_libraries(controller_api INTERFACE)