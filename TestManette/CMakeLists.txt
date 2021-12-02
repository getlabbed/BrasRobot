cmake_minimum_required(VERSION 3.20)
project(TestManette C)

set(CMAKE_C_STANDARD 99)

set(SDL2_INCLUDE_DIR c:/git/TestManette/SDL2/include)
set(SDL2_LIB_DIR c:/git/TestManette/SDL2/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(TestManette main.c Gamepad.c)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
