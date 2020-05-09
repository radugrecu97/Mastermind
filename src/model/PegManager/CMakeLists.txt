add_subdirectory(abstract)

set(SOURCE_FILES
        Peg.cpp
        )

add_library(peg_manager STATIC ${SOURCE_FILES})

target_include_directories(peg_manager
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include/model
        include/
        )

target_link_libraries(peg_manager PUBLIC peg_manager_abs)


