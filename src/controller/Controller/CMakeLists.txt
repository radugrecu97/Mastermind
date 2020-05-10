add_subdirectory(api)

set(SOURCE_FILES
        Controller.cpp
        )

add_library(controller STATIC ${SOURCE_FILES})

target_include_directories(controller
        PUBLIC
        include/
        )

target_link_libraries(controller LINK_PUBLIC controller_api game_state menu game_manager)

