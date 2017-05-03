cmake_minimum_required(VERSION 2.8)

project(Tests)
# The version number.
set (TESTS_VERSION_MAJOR 1)
set (TESTS_VERSION_MINOR 0)
add_compile_options(-std=c++11)
find_package(OpenCV 3.2.0 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
FILE(GLOB_RECURSE TESTS_DIR_INCLUDE "${PROJECT_SOURCE_DIR}/include/*.h")
add_custom_target(headers SOURCES ${TESTS_DIR_INCLUDE})

aux_source_directory(${PROJECT_SOURCE_DIR}/src TESTS_DIR_SRCS)
add_library(${PROJECT_NAME} SHARED ${TESTS_DIR_SRCS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(main "utils/Main.cpp")
target_link_libraries( main ${PROJECT_NAME} )
