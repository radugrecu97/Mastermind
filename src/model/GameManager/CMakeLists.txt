add_subdirectory(api)

set(SOURCE_FILES
        GameManager.cpp
        )

add_library(game_manager STATIC ${SOURCE_FILES})

target_include_directories(game_manager
        PUBLIC
        include/
        )

target_link_libraries(game_manager PUBLIC game_manager_api game_state settings_manager peg_manager util constants)


