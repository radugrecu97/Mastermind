add_subdirectory(api)

set(SOURCE_FILES
        FactoryFrame.cpp
        Main.cpp
        Settings.cpp
        Game.cpp
        Victory.cpp
        Loss.cpp
        )

add_library(frame STATIC ${SOURCE_FILES})

target_include_directories(frame
        PUBLIC
        include/
        )

target_link_libraries(frame LINK_PUBLIC frame_api constants)

