#include "gtest/gtest.h"
#include "../LockingQueue.h"
#include <vector>
#include <string>
#include <thread>
#include <iostream>

void hasData(int data) {
    std::cout << "Got" << data << "\n";
}

TEST(BETWEEN_BRACKETS, CASE1)
{
    LockingQueue<int> Q(hasData);
    for (int i = 0; i < 50; i++) {
        std::cout << i << "\n";
        std::thread th(&LockingQueue<int>::push, &Q, i);
        th.detach();
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}