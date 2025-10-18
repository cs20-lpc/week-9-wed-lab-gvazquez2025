#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ArrayQueue {
private:
    T* data;
    int maxSize;
    int frontIndex;
    int backIndex;
    int length;

public:
    // constructors, destructor
    ArrayQueue(int size = 10);
    ArrayQueue(const ArrayQueue<T>& other);
    ~ArrayQueue();

    // core operations
    void enqueue(const T& item);
    void dequeue();
    T& front();
    T& back();
    void clear();

    // utility
    int getLength() const;
    int getMaxSize() const;
    bool isEmpty() const;
    bool isFull() const;

    // assignment
    ArrayQueue<T>& operator=(const ArrayQueue<T>& other);
};

#include "ArrayQueue.hpp" 

#endif
