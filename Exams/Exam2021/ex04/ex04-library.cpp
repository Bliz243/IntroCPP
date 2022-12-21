#include <iostream>
#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(unsigned int amount) {
    this->amount = amount;
    writeCountNum = 0;
}

void SensorBuffer::write(int value) {
    data.push_back(value);
    writeCountNum++;

    if (writeCountNum > amount) {
        // We only keep the latest necessary values in 'data'
        data.erase(data.begin());
    }
}

int SensorBuffer::read() {
    if(data.empty()) {
        return 0;
    } else {
        return data.back();
    }
}

int SensorBuffer::readAvg() {
    if (this->writeCountNum == 0) {
        return 0;
    }

    int sum = 0; // Will store the sum of buffer values

    // Number of values we can use to compute the average
    unsigned int nvalues = min(writeCountNum, amount);

    for (unsigned int i = 0; i < nvalues; i++) {
        sum += this->data[i];
    }

    return sum / nvalues;
}

unsigned int SensorBuffer::writeCount() {
 return writeCountNum;
}

// Task 4(b).  Write a working implementation of write() and writeCount()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of readAvg()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
