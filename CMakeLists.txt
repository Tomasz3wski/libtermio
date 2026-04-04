cmake_minimum_required(VERSION 3.21)
project(termio)

add_library(termio 
    src/RawTerminal.cpp
    src/ansi.cpp
    )

target_include_directories(termio PUBLIC include)

add_executable(example src/main.cpp)

target_link_libraries(example PRIVATE termio)