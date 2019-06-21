#include "gtest/gtest.h"
#include "../ThreadSafeQueue.h"
#include "../ThreadSafeBlockingQueue.h"


TEST(ThreadSafeQueue, basic)
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


TEST(ThreadSafeBlockingQueue, basic)
{
    ThreadSafeBlockingQueue<int> Q;
    for (int i = 0; i < 100000; ++i) {
        Q.push(i);
    }

    int n = 0;
    for (int i = 0; i < 100000; ++i) {
        Q.pop(n);
    }

    EXPECT_EQ(n, 99999);
}


void PopQueue(ThreadSafeBlockingQueue<int> *Q, int count)
{
    int n = 0;
    for (int i = 0; i < count; i++)
    {
        bool b = Q->pop(n);
    }
}


void PushQueue(ThreadSafeBlockingQueue<int> *Q, int count)
{
    int n = 0;
    for (int i = 0; i < count; i++)
    {
        Q->push(i);
    }
}

TEST(ThreadSafeBlockingQueue, SimultaneousAccess)
{
    ThreadSafeBlockingQueue<int> queue;

    std::thread t1(PopQueue, &queue, 1000000);
    std::thread t2(PushQueue, &queue, 1000000);

    t1.join();
    t2.join();
}


int main(int argc, char **argv) {
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
