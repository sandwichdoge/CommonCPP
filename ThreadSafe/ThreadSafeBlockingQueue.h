#ifndef THREAD_SAFE_BLOCKING_QUEUE_H_
#define THREAD_SAFE_BLOCKING_QUEUE_H_

#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>


template <typename T>
class ThreadSafeBlockingQueue
{
    public:
        ThreadSafeBlockingQueue() : sem(0) {};
        virtual ~ThreadSafeBlockingQueue() {};

        bool pop(T& out);
        void push(T val);
        size_t size();
    private:
        std::queue<T> Q;
        std::mutex m;

        std::mutex mQueue;
        std::condition_variable cv;
        std::atomic<int> sem;
};


template <typename T>
void ThreadSafeBlockingQueue<T>::push(T val)
{
    m.lock();
    Q.push(val);
    m.unlock();

    sem++;
    cv.notify_one();
    //std::cout << sem << ",";
}

template <typename T>
bool ThreadSafeBlockingQueue<T>::pop(T &val)
{
    std::unique_lock<std::mutex> mlock(mQueue);

    cv.wait(mlock, [this] {return this->sem > 0;});
    
    std::lock_guard<std::mutex> lock(m);
    if (Q.empty()) {
        return false;
    }
    val = Q.front();
    Q.pop();

    sem--;
    //std::cout << sem << ",";

    return true;
}

template <typename T>
size_t ThreadSafeBlockingQueue<T>::size()
{
    return Q.size();
}

#endif