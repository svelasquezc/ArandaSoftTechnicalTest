cmake_minimum_required(VERSION 3.13.0)

project(ArandaTechTask VERSION 1.0
  DESCRIPTION "C++ ArandaSoft Technical Test"
  LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_STANDARD 17) 

link_libraries(${CMAKE_DL_LIBS})

#For external dependencies

add_subdirectory(external/SQLite3)

add_subdirectory(external/SOCI)

add_subdirectory(external/googletest)


include_directories(${SQLITE_INCLUDE_DIRECTORY} ${SOCI_INCLUDE_DIRECTORY} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#configure_file(config.h.in config.h)


add_executable(${PROJECT_NAME})

add_library(OSSysInfo STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(OSSysInfo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${SOCI_CORE_LIBRARY} ${SOCI_SQLITE3_LIBRARY} ${SQLITE_LIBRARY} OSSysInfo)


enable_testing()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(GoogleTest)
endif()

#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
#endif()


# Report a complete summary of configuration
include(FeatureSummary)
feature_summary(WHAT ALL)
