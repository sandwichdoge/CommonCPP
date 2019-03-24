#include "gtest/gtest.h"
#include "../StringUtils.h"
#include <vector>
#include <string>


TEST(GROUP1, CASE1)
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


int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
