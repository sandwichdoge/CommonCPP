#include "gtest/gtest.h"
#include "../StringUtils.h"
#include <vector>
#include <string>


TEST(BETWEEN_BRACKETS, CASE1)
{
    std::vector<std::string> v;
    std::string str = "'yes', 'no','maybe'";

    bool ret = StringUtils::betweenBrackets(v, str, '\'');
    EXPECT_EQ(ret, true);

    EXPECT_TRUE(std::string(v[0]) == "yes");
    EXPECT_TRUE(v[1] == "no");
    EXPECT_TRUE(v[2] == "maybe");
}


TEST(CHAR_COUNT, CASE1)
{
    std::string str = "abcd,<<>>0235";
    int n = StringUtils::charCount(str, '>');
    EXPECT_EQ(n, 2);

    n = StringUtils::charCount(str, '_');
    EXPECT_EQ(n, 0);
}


TEST(CHAR_COUNT, CASE2)
{
    std::string str = "abcde\n";
    int n = StringUtils::charCount(str, '\0');
    EXPECT_EQ(n, 0);
}


TEST(STRING_TRIM_LEFT, CASE1)
{
    std::string str = "abc";
    StringUtils::stringTrimLeft(str, 2);

    EXPECT_TRUE(str == "c");
}


TEST(STRING_TRIM_LEFT, CASE2)
{
    std::string str = "abc";
    StringUtils::stringTrimLeft(str, 5);

    EXPECT_TRUE(str == "");
}


TEST(STRING_TRIM_RIGHT, CASE1)
{
    std::string str = "abc";
    StringUtils::stringTrimRight(str, 2);

    EXPECT_TRUE(str == "a");
}

TEST(STRING_TRIM_RIGHT, CASE2)
{
    std::string str = "abc";
    StringUtils::stringTrimRight(str, 3);

    EXPECT_TRUE(str == "");
}


TEST(STRING_REPLACE, CASE1)
{
    std::string str = "a nice doge.";
    StringUtils::stringReplace(str, "doge", "cat");

    EXPECT_TRUE(str == "a nice cat.");
}

TEST(INT_TO_STRING, CASE1)
{
    int n = 2000000000;
    std::string s = StringUtils::intToString(n);
    EXPECT_EQ(s, "2000000000");
}

TEST(INT_TO_STRING, CASE2)
{
    long long n = 2000000000000;
    std::string s = StringUtils::intToString(n);
    EXPECT_EQ(s, "2000000000000");
}

TEST(STRING_TO_INT, CASE1)
{
    std::string s = "3000000";
    int n;
    bool success = StringUtils::StringToInteger(s, n);
    EXPECT_EQ(success, true);
    EXPECT_EQ(n, 3000000);
}

TEST(STRING_TO_INT, CASE2)
{
    std::string s = "3000000000000";
    long long n;
    bool success = StringUtils::StringToInteger(s, n);
    EXPECT_EQ(success, true);
    EXPECT_EQ(n, 3000000000000);
}

int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
