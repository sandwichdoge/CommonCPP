#include "gtest/gtest.h"
#include "../WStringUtils.h"

TEST(WStringConvert, CASE1)
{
    EXPECT_EQ(1, 1);
}

TEST(WStringUtils, WstringToBytes_BytesToWstring)
{
    std::string str = WStringUtils::WstringToBytes( L"Việt" );
    std::wstring wstr = WStringUtils::BytesToWstring(str.c_str());

    std::string str2 = WStringUtils::WstringToBytes( wstr );
    std::wstring wstr2 = WStringUtils::BytesToWstring(str2.c_str());

    EXPECT_EQ( L"Việt",  wstr );
    EXPECT_EQ( L"Việt",  wstr2 );
    EXPECT_EQ( wstr2.length(), 4);

    EXPECT_EQ(wstr2[0], L'V');
    EXPECT_EQ(wstr2[1], L'i');
    EXPECT_EQ(wstr2[2], L'ệ');
    EXPECT_EQ(wstr2[3], L't');
}


TEST(WStringUtils, BytesToWstring_NullPtr)
{
    std::wstring wstr = WStringUtils::BytesToWstring(NULL);
    EXPECT_EQ(wstr, L"");
}


TEST(WStringUtils, WstringToBytes_EmptyString)
{
    std::string s = WStringUtils::WstringToBytes(L"");
    
    EXPECT_EQ(s, "");
}


int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
