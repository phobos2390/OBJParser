set(SOURCE_DIRECTORIES .
                       ./OBJParserTester
                       ./OBJParserTesting)

file(GLOB source_files ${SOURCE_DIRECTORIES}/*.cpp)

set(LIB_NAME lib_${PROJ_NAME}_${REPO_NAME})

add_library(${LIB_NAME}_s STATIC ${source_files})
add_library(${LIB_NAME} SHARED ${source_files})

add_executable(objinfo objinfo/OBJInfo.cpp)
target_link_libraries(objinfo ${LIB_NAME}_s)
