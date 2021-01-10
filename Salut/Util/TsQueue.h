#ifndef SALUT_UTIL_TS_QUEUE_H_
#define SALUT_UTIL_TS_QUEUE_H_
#include <deque>
#include <mutex>

namespace salut {
namespace util {
    /* 线程安全队列 thread safe queue */
    template<class T>
    class TsQueue {
    public:
        TsQueue() = default;
        TsQueue(const TsQueue<T>& other) = delete;
        ~TsQueue() { Clear(); }

        const T& Front()
        {
            std::lock_guard<std::mutex> lk(mtx);
            return tsQue.front();
        }

        const T& Back()
        {
            std::lock_guard<std::mutex> lk(mtx);
            return tsQue.back();
        }

        void PushBack(const T& value)
        {
            std::lock_guard<std::mutex> lk(mtx);
            tsQue.push_back(value);
        }

        void PushFront(const T& value)
        {
            std::lock_guard<std::mutex> lk(mtx);
            tsQue.push_front(value);
        }

        T PopFront()
        {
            std::lock_guard<std::mutex> lk(mtx);
            auto t = std::move(tsQue.front());
            tsQue.pop_front();
            return t;
        }

        T PopBack()
        {
            std::lock_guard<std::mutex> lk(mtx);
            auto t = std::move(tsQue.back());
            tsQue.pop_back();
            return t;
        }

        size_t Size()
        {
            std::lock_guard<std::mutex> lk(mtx);
            return tsQue.size();
        }

        bool Empty()
        {
            std::lock_guard<std::mutex> lk(mtx);
            return tsQue.empty();
        }

        void Clear()
        {
            std::lock_guard<std::mutex> lk(mtx);
            tsQue.clear();
        }

    private:
        std::mutex mtx;
        std::deque<T> tsQue;
    };
}  // namespace util
}  // namespace salut

#endif  // SALUT_UTIL_TS_QUEUE_H_
