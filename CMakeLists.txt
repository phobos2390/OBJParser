cmake_minimum_required(VERSION 2.6.0)
set(PROJ_NAME phobos2390)
set(REPO_NAME OBJParser)

project("${PROJ_NAME}-${REPO_NAME}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("src/${PROJ_NAME}")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

#set(CMAKE_CXX_COMPILER 'g++')
#set(CMAKE_C_COMPILER 'gcc')

set(CMAKE_CXX_FLAGS '-g')

#file(GLOB resources '${CMAKE_CURRENT_SOURCE_DIR}/res/*')
#message("moving ${resources} to binary directory")
#foreach(res ${resources})
#  message("moving ${res} to binary directory")
  message("moving ${CMAKE_CURRENT_SOURCE_DIR}/res to binary ${CMAKE_CURRENT_BINARY_DIR}/src/${PROJ_NAME}/${REPO_NAME}/")
  file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res"
       DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/src/${PROJ_NAME}/${REPO_NAME}/")
#endforeach()

add_subdirectory("src/${PROJ_NAME}/${REPO_NAME}")
