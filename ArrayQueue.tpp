template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    if (i <= 0) {
        throw string("Queue size must be positive");
    }
    maxSize = i;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    for (int i = 0; i < this->length; i++) {
        buffer[(frontIndex + i) % maxSize] = copyObj.buffer[(copyObj.frontIndex + i) % copyObj.maxSize];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Cannot dequeue from empty queue");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
    if (this->length == 0) {
        frontIndex = 0;
        backIndex = -1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        throw string("Cannot enqueue to full queue");
    }
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return buffer[frontIndex];
}
