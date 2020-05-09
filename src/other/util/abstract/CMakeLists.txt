# abstract classes
add_library(util_api INTERFACE)

target_include_directories(util_api
        INTERFACE
        .
        )

target_link_libraries(util_api INTERFACE)