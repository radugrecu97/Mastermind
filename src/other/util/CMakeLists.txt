add_subdirectory(abstract)

set(SOURCE_FILES
        Util.cpp
        )

add_library(util STATIC ${SOURCE_FILES})

target_include_directories(util
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include/model
        include/
        )

target_link_libraries(util PUBLIC util_api constants)


