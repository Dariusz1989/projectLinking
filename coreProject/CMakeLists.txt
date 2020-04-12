cmake_minimum_required(VERSION 3.13)
project(coreProject)

set(CMAKE_CXX_STANDARD 17)

#add_library(coreProject main.cpp testClass.h testClass.cpp)
#add_library(coreProject::coreProject ALIAS coreProject)
#
#target_include_directories(coreProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#
#install(TARGETS coreProject EXPORT projectaTargets
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        RUNTIME DESTINATION bin
#        INCLUDES DESTINATION include
#        )
#
#install(
#        EXPORT projectaTargets
#        NAMESPACE coreProject::
#        FILE projectaConfig.cmake
#        DESTINATION lib/cmake/projecta
#)
#
#
#export(
#        EXPORT projectaTargets
#        FILE "${CMAKE_CURRENT_BINARY_DIR}/projectaConfig.cmake"
#)
#
#export(PACKAGE projecta)


add_executable(coreProject main.cpp testClass.h testClass.cpp)