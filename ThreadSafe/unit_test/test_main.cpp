#include "gtest/gtest.h"
#include "../ThreadSafeQueue.h"


TEST(ThreadSafeQueue, free)
{
    ThreadSafeQueue<int> Q;
    for (int i = 0; i < 100000; ++i) {
        Q.push(i);
    }

    int n = 0;
    for (int i = 0; i < 100000; ++i) {
        Q.pop(n);
    }

    EXPECT_EQ(n, 99999);
}




int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
