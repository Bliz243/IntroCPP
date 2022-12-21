#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

#include <set>
#include <vector>
using namespace std;

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here
class SensorBuffer : public Buffer {
    private:
        unsigned int amount;
        vector<int> data;
        vector<int> averageData;
        unsigned int writeCountNum;
    public:
        SensorBuffer(unsigned int amount);
        void write(int amount);
        int read();
        int readAvg();
        unsigned int writeCount();
};

#endif /* EX04_LIBRARY_H_ */
