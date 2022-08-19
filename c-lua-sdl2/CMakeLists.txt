cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(sdl2-lua-c-template)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Lua REQUIRED)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set (DEBUG_FLAGS
    "-g")

set (OPT_FLAGS
    "-O0")

set (WARN_FLAGS
    "-Wall")

set(GCC_COMPILE_FLAGS 
    "${DEBUG_FLAGS} ${OPT_FLAGS} ${WARN_FLAGS}")

set(CMAKE_C_FLAGS 
    "${CMAKE_C_FLAGS} ${GCC_COMPILE_FLAGS}")

file(GLOB SOURCES "src/*.c")
file(GLOB LIB_SOURCES "lib/*.c")

set(PROJECT_SOURCES
    ${SOURCES} 
    ${LIB_SOURCES}
)

set(PROJECT_INCLUDES
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/lib/
)

include_directories(${PROJECT_INCLUDES}
                    ${LUA_INCLUDE_DIR}
                    ${SDL2_INCLUDE_DIRS}
                    ${SDL2_GFX_INCLUDE_DIRS}
                    ${SDL2_IMAGE_INCLUDE_DIRS}
                    ${SDL2_MIXER_INCLUDE_DIRS}
                    ${SDL2_TTF_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} 
                      ${LUA_LIBRARIES}
                      ${SDL2_LIBRARIES}
                      ${SDL2_GFX_LIBRARIES}
                      ${SDL2_IMAGE_LIBRARIES}
                      ${SDL2_MIXER_LIBRARIES}
                      ${SDL2_TTF_LIBRARIES}
                      )

# run target
add_custom_target("run"
    COMMENT "Running ${PROJECT_NAME}"
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND ./bin/${PROJECT_NAME}
)

# debug target
add_custom_target("debug"
    COMMENT "Debugging with GDB"
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND gdb -tui bin/${PROJECT_NAME}
)

# clean target
set_property(DIRECTORY PROPERTY ADDITIONAL_CLEAN_FILES
    "${PROJECT_SOURCE_DIR}/build/CMakeFiles"
    "${PROJECT_SOURCE_DIR}/build/CMakeCache.txt"
    "${PROJECT_SOURCE_DIR}/build/Makefile"
    "${PROJECT_SOURCE_DIR}/build/cmake_install.cmake"
    "${PROJECT_SOURCE_DIR}/build/lib"
    "${PROJECT_SOURCE_DIR}/build/compile_commands.json"
)

