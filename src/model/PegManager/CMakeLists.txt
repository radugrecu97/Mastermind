add_subdirectory(api)

set(SOURCE_FILES
        PegManager.cpp
        )

add_library(peg_manager STATIC ${SOURCE_FILES})

target_include_directories(peg_manager
        PUBLIC
        include/
        )

target_link_libraries(peg_manager PUBLIC peg_manager_api util)


