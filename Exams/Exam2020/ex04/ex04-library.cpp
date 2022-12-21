#include "ex04-library.h"
#include <iostream>

LimitedBuffer::LimitedBuffer(unsigned int maxSize, int defaultValue) {
    this->maxSize = maxSize;
    this->defaultValue = defaultValue;
    this->occupancyValue = 0;
}

void LimitedBuffer::write(int v) {
    if(occupancy() < this->maxSize){
        this->buffer.push_back(v);
    }
}

int LimitedBuffer::read() {
    if (this->buffer.size() == 0) {
        return this->defaultValue;
    }
    int v = this->buffer[0];
    this->buffer.erase(this->buffer.begin());
    return v;
}

unsigned int LimitedBuffer::occupancy() {
    return buffer.size();
}
Buffer::~Buffer() {
    // Empty destructor
}
