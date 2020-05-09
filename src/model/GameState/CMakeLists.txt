add_subdirectory(api)

set(SOURCE_FILES
        GameState.cpp
        )

add_library(game_state STATIC ${SOURCE_FILES})

target_include_directories(game_state
        PUBLIC
        include/
        )

target_link_libraries(game_state PUBLIC game_state_api)


