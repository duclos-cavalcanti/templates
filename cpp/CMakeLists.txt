cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(project)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set (CMAKE_CXX_STANDARD 11)

set (DEBUG_FLAGS
    "-g")

set (OPT_FLAGS
    "-O0")

set (WARN_FLAGS
    "-Wall")

set(GCC_COMPILE_FLAGS
    "${DEBUG_FLAGS} ${OPT_FLAGS} ${WARN_FLAGS}")

set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

file(GLOB SOURCES "src/*.cpp")

set(PROJECT_SOURCES
    ${SOURCES}
)

set(PROJECT_INCLUDES
    ${PROJECT_SOURCE_DIR}/include/
)

include_directories(${PROJECT_INCLUDES})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# clean
set_property(DIRECTORY PROPERTY ADDITIONAL_CLEAN_FILES
    "${PROJECT_SOURCE_DIR}/build/CMakeFiles"
    "${PROJECT_SOURCE_DIR}/build/CMakeCache.txt"
    "${PROJECT_SOURCE_DIR}/build/Makefile"
    "${PROJECT_SOURCE_DIR}/build/cmake_install.cmake"
    "${PROJECT_SOURCE_DIR}/build/lib"
    # "${PROJECT_SOURCE_DIR}/build/compile_commands.json"
)

add_custom_target("run"
    COMMENT "Running Program"
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND ./bin/${PROJECT_NAME}
)

add_custom_target("debug"
    COMMENT "Debugging with GDB"
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND gdb -tui --args ./bin/${PROJECT_NAME}
)
