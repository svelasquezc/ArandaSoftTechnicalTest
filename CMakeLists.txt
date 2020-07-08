cmake_minimum_required(VERSION 3.13.0)

project(ArandaTechTest VERSION 1.0
  DESCRIPTION "C++ ArandaSoft Technical Test"
  LANGUAGES CXX C)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_STANDARD 17) 

find_package(SQLite3 CONFIG)
if(NOT SQLite3)
  
#  execute_process(
#    COMMAND
#    git submodule update --init
#    WORKING_DIRECTORY
#    ${CMAKE_CURRENT_SOURCE_DIR}/external/sqlite-amalgamation
#    )
#
#  set(SQLITE3_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/sqlite-amalgamation)
#
#  
#  add_subdirectory(external/sqlite-amalgamation)

add_subdirectory(external/SQLite3)
  
endif()

find_package(Soci)
if(NOT Soci)
  
#  add_custom_target(Soci
#    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#    "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
#    "-DSOCI_STATIC=ON" "-DSOCI_SHARED=OFF" "-DSOCI_TESTS=OFF"
#    "-DSOCI_CXX11=ON" "-DSOCI_LIBDIR=lib" "-DSOCI_EMPTY=ON"
#    "-DWITH_SQLITE3=ON" "-DWITH_POSTGRESQL=OFF"
#    "-DWITH_BOOST=OFF" "-DWITH_DB2=OFF" "-DWITH_ODBC=OFF"
#    "-DWITH_ORACLE=OFF" "-DWITH_MYSQL=OFF"
#    "-DSQLITE3_INCLUDE_DIR=${SQLITE3_INCLUDE_DIR}"
#    WORKING_DIRECTORY
#    ${CMAKE_CURRENT_SOURCE_DIR}/external/soci
#    )

add_subdirectory(external/SOCI)

endif()

#For external dependencies


#configure_file(config.h.in config.h)



add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include) 


target_link_libraries(${PROJECT_NAME} soci-core soci-sqlite3 SQLite::SQLite3)


enable_testing()
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  #ADD_SUBDIRECTORY(tests)
endif()


# Report a complete summary of configuration
include(FeatureSummary)
feature_summary(WHAT ALL)
