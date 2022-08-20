cmake_minimum_required (VERSION 3.0)
project(OpenMPI-Tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# We need the MPI Package, it is installed in a way that you can find it via CMake
find_package(MPI REQUIRED)

# Here the include for MPI are added
include_directories(${MPI_INCLUDE_PATH})

# Create executable as usual, several at once are also possible
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

foreach(src ${SOURCES})
    set (target_file "")
    get_filename_component(target_file ${src} NAME)

    string(REGEX REPLACE  ".cpp" "" target "${target_file}")
    message("Target: ${target} and Target File: ${target_file}")

    add_executable(${target} src/${target_file})
    target_link_libraries(${target} ${MPI_LIBRARIES} -lpthread)
endforeach()

set_property(DIRECTORY PROPERTY ADDITIONAL_CLEAN_FILES
    "${PROJECT_SOURCE_DIR}/build/CMakeFiles"
    "${PROJECT_SOURCE_DIR}/build/CMakeCache.txt"
    "${PROJECT_SOURCE_DIR}/build/Makefile"
    "${PROJECT_SOURCE_DIR}/build/cmake_install.cmake"
    # "${PROJECT_SOURCE_DIR}/build/compile_commands.json"
)
