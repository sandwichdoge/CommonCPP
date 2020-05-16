#include <iostream>
#include "LockingQueue.h"

#define THREAD_COUNT 20000

void prnt(int& n) {
    std::cout << n << "\n";
}

int main() {
    std::thread th[THREAD_COUNT];
    LockingQueue<int> q(prnt);
    for (int i = 0; i < THREAD_COUNT; i++) {
        th[i] = std::thread(&LockingQueue<int>::push, &q, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
    for (int i = 0; i < THREAD_COUNT; i++) {
        th[i].join();
    }
    return 0;
}