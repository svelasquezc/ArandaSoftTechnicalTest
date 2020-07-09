
add_executable(DatabaseTestExe)

target_sources(DatabaseTestExe PRIVATE DatabaseTest.cpp)

target_link_libraries(DatabaseTestExe PRIVATE gtest_main ${SOCI_CORE_LIBRARY} ${SOCI_SQLITE3_LIBRARY} ${SQLITE_LIBRARY})

add_test(NAME DatabaseTest COMMAND DatabaseTestExe)
