#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

#include "ArrayQueue.h"
#include <stdexcept>

template <typename T>
ArrayQueue<T>::ArrayQueue(int size)
    : maxSize(size), frontIndex(0), backIndex(-1), length(0) {
    data = new T[maxSize];
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& other)
    : maxSize(other.maxSize),
      frontIndex(other.frontIndex),
      backIndex(other.backIndex),
      length(other.length) {
    data = new T[maxSize];
    for (int i = 0; i < maxSize; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] data;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& item) {
    if (isFull()) throw string("queue is full");
    backIndex = (backIndex + 1) % maxSize;
    data[backIndex] = item;
    length++;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) throw string("queue is empty");
    frontIndex = (frontIndex + 1) % maxSize;
    length--;
}

template <typename T>
T& ArrayQueue<T>::front() {
    if (isEmpty()) throw string("queue is empty");
    return data[frontIndex];
}

template <typename T>
T& ArrayQueue<T>::back() {
    if (isEmpty()) throw string("queue is empty");
    return data[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    frontIndex = 0;
    backIndex = -1;
    length = 0;
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return length == maxSize;
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& other) {
    if (this != &other) {
        delete[] data;
        maxSize = other.maxSize;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;
        length = other.length;
        data = new T[maxSize];
        for (int i = 0; i < maxSize; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

#endif
