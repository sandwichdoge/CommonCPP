#include "gtest/gtest.h"
#include "../Regexp.h"


TEST(SEARCH, CASE1)
{
    std::string s = "Today I found 2 fresh apples and 3 rotten bananas";
    std::string ptn = "([0-9]) fresh (apples|bananas)";
    std::vector<std::string> v;

    bool ret = Regexp::search(s, ptn, v);
    EXPECT_EQ(ret, true);
    EXPECT_TRUE(v[0] == "2 fresh apples");
}


TEST(REPLACE, CASE1)
{
    std::string s = "Today I found 2 fresh apples and 3 rotten bananas";
    std::string ptn = "([0-9]) fresh (apples|bananas)";

    Regexp::replace(s, ptn, "$1 okay $2");
    EXPECT_TRUE(s == "Today I found 2 okay apples and 3 rotten bananas");
}


int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
