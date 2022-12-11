#include "shareddata.h"
#include <iostream>

SharedData::SharedData()
{
    pthread_mutex_init(&mLock, NULL);
    pthread_cond_init(&mBufferFull, NULL);
    pthread_cond_init(&mBufferEmpty, NULL);
    mData = new int [DATASIZE];
}

SharedData::~SharedData()
{
    pthread_mutex_destroy(&mLock);
    pthread_cond_destroy(&mBufferFull);
    pthread_cond_destroy(&mBufferEmpty);
    delete []mData;
}

int SharedData::getValue()
{
    int returnValue;

    pthread_mutex_lock(&mLock);

    while(mIndex == -1){
        std::cout << "Buffer Empty" << std::endl;
        pthread_cond_wait(&mBufferEmpty, &mLock);
    }

    returnValue = mData[mIndex--];

    std::cout << std::to_string(mIndex) << "." << "ConsumedValue:" << std::to_string(returnValue) << std::endl;

    pthread_cond_signal(&mBufferFull);

    pthread_mutex_unlock(&mLock);

    return returnValue;
}

void SharedData::setValue(int pValue)
{
    pthread_mutex_lock(&mLock);

    while(mIndex == (DATASIZE - 1)){
        std::cout << "Buffer Full" << std::endl;
        pthread_cond_wait(&mBufferFull, &mLock);
    }

    mData[++mIndex] = pValue;

    std::cout << std::to_string(mIndex) << "." << "ProducedValue:" << std::to_string(pValue) << std::endl;

    pthread_cond_signal(&mBufferEmpty);

    pthread_mutex_unlock(&mLock);
}
