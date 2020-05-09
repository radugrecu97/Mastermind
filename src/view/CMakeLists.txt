cmake_minimum_required(VERSION 3.16)
project(view)

#set(SOURCE_FILES controller.cpp)

#add_library(view STATIC ${SOURCE_FILES})
target_include_directories(view
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include/view
        )

#target_link_libraries(view PUBLIC)