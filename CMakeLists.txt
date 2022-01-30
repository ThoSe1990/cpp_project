

cmake_minimum_required(VERSION 3.16)



project(HelloWorld LANGUAGES CXX)

add_library(project_options INTERFACE)



include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

include(cmake/StaticAnalyzers.cmake)

add_library(project_warnings INTERFACE)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)





option(ENABLE_PCH "Enable Precompiled Headers" ON)
if(ENABLE_PCH)
  target_precompile_headers(
    project_options
    INTERFACE
    <iostream>
    <vector>
    <string>
    <map>
    <utility>)
endif()



add_subdirectory(${PROJECT_SOURCE_DIR}/src)
