cmake_minimum_required(VERSION 3.11)

configure_file(CMakeLists.txt.in sqlite-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sqlite-download)
if(result)
  message(FATAL_ERROR "CMake step for sqlite failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sqlite-download)
if(result)
  message(FATAL_ERROR "Build step for sqlite failed: ${result}")
endif()

set(SQLITE_CANDIDATES sqlite3)
if(WIN32)
  list(APPEND SQLITE_CORE_CANDIDATES libsqlite3)
endif()

# Since sqlite is not installed, need to find the library and header myself.
find_path(SQLITE_INCLUDE_DIRECTORY
  NAMES sqlite3.h
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/sqlite-build
  PATH_SUFFIXES include
  DOC "SQLITE include directory"
  NO_DEFAULT_PATH)

find_library(SQLITE_LIBRARY
  NAMES ${SQLITE_CANDIDATES}
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/sqlite-build
  PATH_SUFFIXES lib64 lib a
  DOC "SQLITE core library"
  NO_DEFAULT_PATH)

if(NOT SQLITE_INCLUDE_DIRECTORY)
  message(FATAL_ERROR "SQLITE_INCLUDE_DIRECTORY is not found.")
endif()

if(NOT SQLITE_LIBRARY)
  message(FATAL_ERROR "SQLITE_LIBRARY is not found.")
endif()
