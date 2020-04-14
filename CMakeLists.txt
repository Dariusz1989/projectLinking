cmake_minimum_required(VERSION 3.15)

project(yourapp LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_USE_QTGUI TRUE)
set(QT_USE_QTXML TRUE)

ADD_DEFINITIONS(-DQT_NO_KEYWORDS)
add_definitions(${QT_DEFINITIONS} -DQT_MESSAGELOGCONTEXT)
ADD_DEFINITIONS(-D_USE_MATH_DEFINES)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(OpenGL REQUIRED)

#example usage MakeLibTarget(some_lib STATIC "${sources}" "${include_dirs}" "${libs_to_link}")
#static libs obsiously arent **linked** to a lib X being created by this call, but by using PUBLIC keyword in target_link_libraries() they will be linked to an executable which links this lib X
#include dirs are also inherited/forwarded in the same manner when using PUBLIC keyword
macro(MakeLibTarget libname type sources incldirs deps)
    message("MakeLibTarget(${libname}) deps=: ${deps}")
    add_library(${libname} ${type} ${sources})

    target_include_directories(${libname} PUBLIC ${incldirs})

    target_link_libraries(${libname} PUBLIC ${deps})

    set_target_properties(
            ${libname} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
            ${libname} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
            ${libname} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    )
    # Configure output name depending on debug mode
    if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
        set_target_properties(${libname} PROPERTIES SUFFIX "d.lib")
        set_target_properties(${libname} PROPERTIES OUTPUT_NAME ${libname}) #most likely not needed
    else ()
        set_target_properties(${libname} PROPERTIES SUFFIX ".lib")
        set_target_properties(${libname} PROPERTIES OUTPUT_NAME ${libname}) #most likely not needed
    endif ()
endmacro()

macro(MakeTestExeTarget libname sources)
    set(exename ${libname}_test)
    add_executable(${exename} ${sources})

    add_dependencies(${exename} ${libname})

    set_target_properties(${exename} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib") #?? test exe should also go there?)
    # Configure output name depending on debug mode
    if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
        set_target_properties(${exename} PROPERTIES SUFFIX "d.lib")
        set_target_properties(${exename} PROPERTIES OUTPUT_NAME ${exename}) #most likely not needed
    else ()
        set_target_properties(${exename} PROPERTIES SUFFIX ".lib")
        set_target_properties(${exename} PROPERTIES OUTPUT_NAME ${exename}) #most likely not needed
    endif ()
endmacro()


#in this order
add_subdirectory(extraItems)
add_subdirectory(coreProject)
add_subdirectory(projectA)
add_subdirectory(projectB)

add_executable(mainapp main.cpp)
target_link_libraries(mainapp PRIVATE projB extra) #Qt libs should be inherited from `projB` and `extra` targets, incl dirs just as well
add_dependencies(mainapp projB extra)