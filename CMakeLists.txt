cmake_minimum_required(VERSION 2.6.0)
set(PROJ_NAME phobos2390)
set(REPO_NAME OBJParser)

project("${PROJ_NAME}-${REPO_NAME}")
enable_language(CXX)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
add_subdirectory("src/${PROJ_NAME}/${REPO_NAME}")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set(CMAKE_CXX_COMPILER 'g++')
set(CMAKE_C_COMPILER 'gcc')

set(CMAKE_CXX_FLAGS '-g -m64')

