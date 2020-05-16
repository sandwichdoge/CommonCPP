#ifndef INCLUDE_LOCKING_QUEUE_H
#define INCLUDE_LOCKING_QUEUE_H
#include <thread>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <queue>

// Start queue in a new thread, as soon as there's data in queue, process it 
// with a user-specified callback function.
template <typename T>
class LockingQueue {
public:
    LockingQueue(std::function<void(T&)> cb);
    virtual ~LockingQueue();
    // Put data in queue, process it as soon as ready.
    void push(T);

private:
    void _loop();
    std::queue<T> _Q;
    std::function<void(T&)> _cb;
    std::thread _th;
    std::mutex _m;
    std::condition_variable _cv;
    std::atomic_bool _running;
    std::atomic_uint32_t _dataInQueue;
};

template <typename T>
LockingQueue<T>::LockingQueue(std::function<void(T&)> cb) {
    _cb = cb;
    _running = true;
    _dataInQueue = 0;
    _th = std::thread(&LockingQueue::_loop, this);
}
template <typename T>
LockingQueue<T>::~LockingQueue() {
    _running = false;
    _cv.notify_all();
    _th.join();
}

template <typename T>
void LockingQueue<T>::_loop() {
    while (_running) {
        std::unique_lock<std::mutex> mlock(_m);
        _cv.wait(mlock, [this] { return (this->_dataInQueue > 0 || !_running); });
        if (_Q.empty() && !_running) {
            break;
        }
        T data = _Q.front();
        _Q.pop();
        _cb(data);
        this->_dataInQueue--;
    }
}

template <typename T>
void LockingQueue<T>::push(T data) {
    _Q.push(data);
    _dataInQueue++;
    _cv.notify_one();
}

#endif
