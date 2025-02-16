cmake_minimum_required(VERSION 3.11)

configure_file(CMakeSoci.txt.in soci-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/soci-download)
if(result)
  message(FATAL_ERROR "CMake step for soci failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/soci-download)
if(result)
  message(FATAL_ERROR "Build step for soci failed: ${result}")
endif()

set(SOCI_CORE_CANDIDATES soci_core_4_0 soci_core)
if(WIN32)
  list(APPEND SOCI_CORE_CANDIDATES libsoci_core_4_0 libsoci_core)
endif()

set(SOCI_EMPTY_CANDIDATES soci_empty_4_0 soci_empty)
if(WIN32)
  list(APPEND SOCI_EMPTY_CANDIDATES libsoci_empty_4_0 libsoci_empty)
endif()

# Since soci is not installed, need to find the library and header myself.
find_path(SOCI_INCLUDE_DIRECTORY
  NAMES soci/soci.h soci/soci-backend.h
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/soci-build
  PATH_SUFFIXES include
  DOC "SOCI include directory"
  NO_DEFAULT_PATH)

find_library(SOCI_CORE_LIBRARY
  NAMES ${SOCI_CORE_CANDIDATES}
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/soci-build
  PATH_SUFFIXES lib64 lib
  DOC "SOCI core library"
  NO_DEFAULT_PATH)

find_library(SOCI_EMPTY_LIBRARY
  NAMES ${SOCI_EMPTY_CANDIDATES}
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/soci-build
  PATH_SUFFIXES lib64 lib
  DOC "SOCI empty backend library"
  NO_DEFAULT_PATH)

find_library(SOCI_SQLITE3_LIBRARY
  NAMES ${SOCI_SQLITE3_CANDIDATES}
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/soci-build
  PATH_SUFFIXES lib64 lib
  DOC "SOCI sqilite3 backend library"
  NO_DEFAULT_PATH)


if(NOT SOCI_INCLUDE_DIRECTORY)
  message(FATAL_ERROR "SOCI_INCLUDE_DIRECTORY is not found.")
endif()

if(NOT SOCI_CORE_LIBRARY)
  message(FATAL_ERROR "SOCI_CORE_LIBRARY is not found.")
endif()

if(NOT SOCI_EMPTY_LIBRARY)
  message(FATAL_ERROR "SOCI_EMPTY_LIBRARY is not found.")
endif()
