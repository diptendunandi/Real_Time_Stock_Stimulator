#ifndef LOCKFREEQUEUE_H
#define LOCKFREEQUEUE_H

#include <atomic>
#include <vector>
using namespace std;

// Single Producer - Single Consumer
template<typename T>
class LockFreeQueue {
    vector<T> buffer;
    atomic<size_t> head, tail;
    size_t capacity;

public:
    LockFreeQueue(size_t cap)
        : buffer(cap), head(0), tail(0), capacity(cap) {}

    bool push(const T& item) {
        size_t next = (head + 1) % capacity;
        if (next == tail.load()) return false;
        buffer[head] = item;
        head.store(next);
        return true;
    }

    bool pop(T& item) {
        if (tail.load() == head.load()) return false;
        item = buffer[tail];
        tail.store((tail + 1) % capacity);
        return true;
    }
};

#endif
