#include "gtest/gtest.h"
#include "../ini.h"
#include <string>

std::string static_content = "[my_section]\n\
key1=value1\n\
key2=value2\n\
key3=value3\n";


TEST(INI_READ, CASE1)
{
    std::string out = "";
    ini::IniRead(static_content, "my_section", "key3", out);
    
    EXPECT_TRUE(out == "value3");
};


TEST(INI_READ, CASE2)
{
    std::string out = "";
    bool ret = ini::IniRead(static_content, "my_section", "", out);

    EXPECT_TRUE(out == "" && ret == false);
}


TEST(INI_READ, CASE3)
{
    std::string out = "";
    bool ret = ini::IniRead(static_content, "", "key1", out);

    EXPECT_TRUE(out == "" && ret == false);
}


TEST(INI_READ, CASE4)
{
    std::string out = "";
    bool ret = ini::IniRead("", "my_section", "key1", out);

    EXPECT_TRUE(out == "" && ret == false);
}


TEST(INI_READ, CASE5)
{
    std::string out = "";
    bool ret = ini::IniRead(static_content, "non_existent_sect", "key1", out);

    EXPECT_TRUE(out == "" && ret == false);
}


TEST(INI_WRITE, CASE1)
{
    std::string local_content = "\n";
    bool ret = ini::IniWrite(local_content, "sect", "key", "val");

    std::string out = "";
    ini::IniRead(local_content, "sect", "key", out);
    
    EXPECT_TRUE(out == "val" && ret == true);
}


TEST(INI_WRITE, CASE2)
{
    std::string local_content = "";
    bool ret = ini::IniWrite(local_content, "sect", "key", "val");
    ret &= ini::IniWrite(local_content, "sect", "key", "");

    std::string out;
    ini::IniRead(local_content, "sect", "key", out);
    
    EXPECT_TRUE(out == "" && ret == true);
}


TEST(INI_BOTH, CASE1)
{
    std::string local_content = "[sect]";
    bool ret = ini::IniWrite(local_content, "sect", "key", "val");

    std::string out;
    ret &= ini::IniRead(local_content, "sect", "key", out);
    
    EXPECT_TRUE(out == "val" && ret == true);
}


TEST(INI_BOTH, CASE2)
{
    ini::IniWrite(static_content, "my_section", "key3", "THREE");
    ini::IniWrite(static_content, "new_sect", "key3", "DREI");
    ini::IniWrite(static_content, "new_sect", "key4", "VIER");

    std::string out = "";

    ini::IniRead(static_content, "my_section", "key3", out);
    EXPECT_TRUE(out == "THREE");

    ini::IniRead(static_content, "new_sect", "key3", out);
    EXPECT_TRUE(out == "DREI");

    ini::IniRead(static_content, "new_sect", "key4", out);
    EXPECT_TRUE(out == "VIER");
}



int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
