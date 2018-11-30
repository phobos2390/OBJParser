set(SOURCE_DIRECTORIES .
                       ./OBJParserTester
                       ./OBJParserTesting)

file(GLOB source_files ${SOURCE_DIRECTORIES}/*.cpp)

add_library(lib_${PROJECT_NAME}_${REPO_NAME} ${source_files})

