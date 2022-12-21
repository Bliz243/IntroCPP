#include "ex04-library.h"
// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods
FilteringBuffer::FilteringBuffer(int defaultValue) {
    this->defaultValue = defaultValue;
}

void FilteringBuffer::write(int value) {
    if(memory.find(value) != memory.end()) {
        return;
    } else {
        data.push_back(value);
        memory.insert(value);
    }
}

int FilteringBuffer::read() {
    if(data.size() == 0) {
        return defaultValue;
    } else {
        int temp = data[0];
        data.erase(data.begin());
        return temp;
    }
}

unsigned int FilteringBuffer::occupancy() {
    return data.size();
}

void FilteringBuffer::reset() {
    data.clear();
    memory.clear();
}

// Task 4(b).  Write a working implementation of write() and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of reset()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}