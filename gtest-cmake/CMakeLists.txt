cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(PROJECT_NAME
    gtest-template)

set(PROJECT_TEST_NAME
    gtest-template-test)

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES
     "src/*.c")
file(GLOB LIB_SOURCES
     "lib/*.c")


SET(PROJECT_SOURCES
    ${SOURCES}
    ${LIB_SOURCES}
)

SET(PROJECT_INCLUDES
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/lib/include
)

set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_INCLUDES})

add_executable(${PROJECT_NAME}
               ${PROJECT_SOURCES})

set_property(DIRECTORY PROPERTY ADDITIONAL_CLEAN_FILES
    "${PROJECT_SOURCE_DIR}/build/CMakeFiles"
    "${PROJECT_SOURCE_DIR}/build/CMakeCache.txt"
    "${PROJECT_SOURCE_DIR}/build/Makefile"
    "${PROJECT_SOURCE_DIR}/build/cmake_install.cmake"
    "${PROJECT_SOURCE_DIR}/build/lib"
    # "${PROJECT_SOURCE_DIR}/build/compile_commands.json"
)
include(docs)
include(run)
include(debug)
