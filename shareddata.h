#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <pthread.h>

class SharedData
{
public:
    SharedData();
    ~SharedData();
    int getValue();
    void setValue(int pValue);
private:
    static constexpr int DATASIZE = 1000;
    int *mData = NULL;
    int mIndex = -1;
    pthread_mutex_t mLock;
    pthread_cond_t mBufferFull;
    pthread_cond_t mBufferEmpty;
};

#endif // SHAREDDATA_H
