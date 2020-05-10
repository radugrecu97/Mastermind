add_subdirectory(api)

set(SOURCE_FILES
        FactoryMenu.cpp
        Menu.cpp
        Main.cpp
        Settings.cpp
        InputMaxTurns.cpp
        InputBlanks.cpp
        InputDuplicates.cpp
        InputCodePegs.cpp
        InputKeyPegs.cpp
        )

add_library(menu STATIC ${SOURCE_FILES})

target_include_directories(menu
        PUBLIC
        include/
        )

target_link_libraries(menu LINK_PUBLIC menu_api command constants)

