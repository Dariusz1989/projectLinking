cmake_minimum_required(VERSION 3.13)
project(coreProject)

set(CMAKE_CXX_STANDARD 17)

add_library(coreProject main.cpp testClass.h testClass.cpp)
target_include_directories(coreProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(coreProject main.cpp testClass.h testClass.cpp)