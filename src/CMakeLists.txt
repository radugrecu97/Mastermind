#add_subdirectory(controller)
add_subdirectory(model)
#add_subdirectory(view)

set(SOURCE_FILES main.cpp)

add_executable(Mastermind ${SOURCE_FILES})

target_link_libraries(Mastermind LINK_PUBLIC peg_manager)