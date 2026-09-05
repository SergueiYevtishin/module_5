cmake_minimum_required(VERSION 4.4.0)
project (
    lesson4
    VERSION 1.0
    DESCRIPTION "first project"
    LANGUAGES CXX
)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)
add_executable(lesson4)
#add_library(lesson4)

set(sources 
main.cpp)

target_sources(lesson4 PRIVATE ${sources})