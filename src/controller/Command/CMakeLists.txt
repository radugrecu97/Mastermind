add_subdirectory(api)

set(SOURCE_FILES
        FactoryCommand.cpp
        ChangeMenu.cpp
        ChangeSetting.cpp
        Command.cpp
        )

add_library(command STATIC ${SOURCE_FILES})

target_include_directories(command
        PUBLIC
        include/
        )

target_link_libraries(command LINK_PUBLIC command_api controller constants)

