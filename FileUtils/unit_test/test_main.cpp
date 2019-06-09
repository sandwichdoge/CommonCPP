#include "gtest/gtest.h"
#include "../FileUtils.h"
#include <string>
#include <iostream>

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



int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
