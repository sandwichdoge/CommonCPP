#ifndef THREAD_SAFE_VECTOR_H_
#define THREAD_SAFE_VECTOR_H_

#include <thread>
#include <vector>
#include <mutex>


template <typename T>
class ThreadSafeVector
{
    public:
        ThreadSafeVector() {};
        virtual ~ThreadSafeVector() {};

        void push_back(T val);
        size_t size();
    private:
        std::vector<T> Q;
        std::mutex m;
};


template <typename T>
void ThreadSafeVector<T>::push_back(T val)
{
    m.lock();
    Q.push_back(val);
    m.unlock();
}


template <typename T>
size_t ThreadSafeVector<T>::size()
{
    return Q.size();
}

#endif