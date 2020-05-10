add_subdirectory(api)

set(SOURCE_FILES
        Main.cpp
        FactoryMenu.cpp
        )

add_library(menu STATIC ${SOURCE_FILES})

target_include_directories(menu
        PUBLIC
        include/
        )

target_link_libraries(menu LINK_PUBLIC menu_api command constants)

