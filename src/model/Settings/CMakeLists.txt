add_subdirectory(api)

set(SOURCE_FILES
        ViewDataFactory.cpp
        ViewGame.cpp
        ViewMain.cpp
        ViewSettings.cpp
        )

add_library(viewdata STATIC ${SOURCE_FILES})

target_include_directories(viewdata
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include/model
        include/
        )

target_link_libraries(viewdata LINK_PUBLIC viewdata_abs)

