set(SOURCE_DIRECTORIES .
                       ./OBJParserTester)
                       #./OBJParserTesting)

set(all_source_files "")
foreach(source_dir ${SOURCE_DIRECTORIES})
  message("Finding everything in ${source_dir}")
  file(GLOB dir_src_files ${source_dir}/*.cpp)
  set(all_source_files ${all_source_files}
                       ${dir_src_files})   
endforeach()

set(LIB_NAME_SHARED ${PROJ_NAME}_${REPO_NAME})
set(LIB_NAME_STATIC ${PROJ_NAME}_${REPO_NAME}_s)

message("Building static library ${LIB_NAME_STATIC} with ${all_source_files}")
add_library(${LIB_NAME_STATIC} STATIC ${all_source_files})
message("Building shared library ${LIB_NAME_SHARED} with ${all_source_files}")
add_library(${LIB_NAME_SHARED} SHARED ${all_source_files})

add_executable(objinfo objinfo/OBJInfo.cpp)
target_link_libraries(objinfo ${LIB_NAME_STATIC})
