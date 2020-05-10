add_subdirectory(api)

set(SOURCE_FILES
        View.cpp
        )

add_library(view STATIC ${SOURCE_FILES})

target_include_directories(view
        PUBLIC
        include/
        )

target_link_libraries(view LINK_PUBLIC view_api game_state command frame)

