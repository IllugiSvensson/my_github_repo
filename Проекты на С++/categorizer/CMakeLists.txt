CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(categorizer)

file(GLOB sources "src/*.cpp")

file(GLOB HEADERS "include/*.hpp")

add_executable(categorizer ${sources})

target_include_directories(categorizer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
