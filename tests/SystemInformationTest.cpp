
#include "SystemInformation.hpp"
#include <gtest/gtest.h>

#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

using namespace soci;


TEST(SystemInformationTest, CreatesSystem){

    backend_factory const &back_end = *soci::factory_sqlite3();
    std::string connection_file_name("db=test_db.sqlite timeout=2 shared_cache=true");
    soci::session sql(back_end, connection_file_name);
    
    auto os_sys_info = makeSystemInformation<soci::session>();
};
