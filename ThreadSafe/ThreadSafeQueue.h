#ifndef THREAD_SAFE_QUEUE_H_
#define THREAD_SAFE_QUEUE_H_

#include <thread>
#include <queue>
#include <mutex>


template <typename T>
class ThreadSafeQueue
{
    public:
        ThreadSafeQueue() {};
        virtual ~ThreadSafeQueue() {};

        bool pop(T& out);
        void push(T val);
        size_t size();
    private:
        std::queue<T> Q;
        std::mutex m;
};


template <typename T>
void ThreadSafeQueue<T>::push(T val)
{
    m.lock();
    Q.push(val);
    m.unlock();
}

template <typename T>
bool ThreadSafeQueue<T>::pop(T &val)
{
    std::lock_guard<std::mutex> lock(m);
    if (Q.empty()) {
        return false;
    }
    val = Q.front();
    Q.pop();

    return true;
}

template <typename T>
size_t ThreadSafeQueue<T>::size()
{
    return Q.size();
}

#endif