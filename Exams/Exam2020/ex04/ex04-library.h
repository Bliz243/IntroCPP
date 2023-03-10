#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};


#include <vector>
#include <string>

using namespace std;

class LimitedBuffer : public Buffer {
private:
    unsigned int occupancyValue;
    unsigned int maxSize;
    int defaultValue;
    vector<int> buffer;
public:
    LimitedBuffer(unsigned int size, int defaultValue);
    void write(int v);
    int read();
    unsigned int occupancy();
};

#endif /* EX04_LIBRARY_H_ */
