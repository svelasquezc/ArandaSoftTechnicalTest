add_executable(DatabaseTestExe)

target_sources(DatabaseTestExe PRIVATE DatabaseTest.cpp)

target_link_libraries(DatabaseTestExe PRIVATE gtest_main gtest ${SOCI_SQLITE3_LIBRARY} ${SOCI_CORE_LIBRARY} ${SQLITE_LIBRARY})

add_test(NAME DatabaseTest COMMAND DatabaseTestExe)


add_executable(SystemInformationTestExe)
target_sources(SystemInformationTestExe PRIVATE SystemInformationTest.cpp)

target_link_libraries(SystemInformationTestExe PRIVATE gtest_main gtest ${SOCI_SQLITE3_LIBRARY} ${SOCI_CORE_LIBRARY} ${SQLITE_LIBRARY} OSSysInfo)

add_test(NAME SystemInformationTest COMMAND SystemInformationTestExe)
