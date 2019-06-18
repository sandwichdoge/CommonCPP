#include "gtest/gtest.h"
#include "../FileUtils.h"
#include <string>
#include <iostream>
#include <string.h>

TEST(FileUtils, readFile_stringPath)
{
    std::string out;
    std::string path = "unit_test/sample.txt";
    FileUtils::readFile(path, out);

    EXPECT_EQ(out, "Lorem\nIpsum");
}


TEST(FileUtils, readFile_charPath)
{
    std::string out;
    const char *path = "unit_test/sample.txt";
    FileUtils::readFile(path, out);

    EXPECT_EQ(out, "Lorem\nIpsum");
}


TEST(FileUtils, readFile_empty)
{
    std::string out;
    FileUtils::readFile("unit_test/sasdfdf.txt", out);

    EXPECT_EQ(out, "");
}


TEST(FileUtils, readFile_buffer)
{
    char buf[128]; 

    FileUtils::readFile("unit_test/sample.txt", buf, sizeof(buf));

    EXPECT_TRUE(strcmp(buf, "Lorem\nIpsum") == 0);
}


TEST(FileUtils, writeFile_basic)
{
    std::string path = "unit_test/write_test.txt";
    std::string data = "Eins Zwei Drei Vier Funf";

    FileUtils::writeFile(path, data);

    std::string out;
    FileUtils::readFile(path, out);

    EXPECT_EQ(out, data);
}


TEST(FileUtils, writeFile_truncate)
{
    std::string path = "unit_test/write_test.txt";
    std::string data = "Eins Zwei Drei Vier Funf";

    FileUtils::writeFile(path, data);

    FileUtils::writeFile(path, "12345");

    std::string out;
    FileUtils::readFile(path, out);

    EXPECT_EQ(out, "12345");
}


TEST(FileUtils, writeFile_buffer)
{
    std::string path = "unit_test/write_test.txt";
    const char *data = "Hello there";

    FileUtils::writeFile(path, data, strlen(data));

    std::string out;
    FileUtils::readFile(path, out);
    
    EXPECT_EQ(std::string(data), out);
    EXPECT_TRUE(strcmp(data, out.c_str()) == 0);
}

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
