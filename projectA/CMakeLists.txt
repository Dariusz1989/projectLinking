cmake_minimum_required(VERSION 3.13)
project(projectA)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(coreProjectDir "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
SET(coreProject ${coreProjectDir}/coreProject/)
add_subdirectory(${coreProject} [EXCLUDE_FROM_ALL])

add_executable(projectA main.cpp)

