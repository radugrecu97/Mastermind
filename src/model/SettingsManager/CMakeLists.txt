add_subdirectory(api)

set(SOURCE_FILES
        SettingsManager.cpp
        )

add_library(settings_manager STATIC ${SOURCE_FILES})

target_include_directories(settings_manager
        PUBLIC
        include/
        )

target_link_libraries(settings_manager LINK_PUBLIC settings_manager_api constants)

