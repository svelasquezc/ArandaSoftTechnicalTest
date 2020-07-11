#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>
#include <gtest/gtest.h>

#include <string>

using namespace soci;


TEST(DatabaseTest, HandlesConn){
    
    backend_factory const &back_end = *soci::factory_sqlite3();
    std::string connection_file_name("db=test_db.sqlite timeout=2 shared_cache=true");
    soci::session sql(back_end, connection_file_name);
    ASSERT_TRUE(true);
};
