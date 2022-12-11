#include "athread.h"
#include <iostream>
#include <unistd.h>
AThread::AThread()
{

}

int AThread::start()
{
    if(!mThreadStarted){
        mThreadStarted = pthread_create(&mThread, NULL, &AThread::loop, this) == 0;
        return mThreadStarted ? 0 : -1;
    }

    return -1;
}

int AThread::wait()
{
    return pthread_join(mThread, NULL);
}

void AThread::quit()
{
    mLoop = false;
}

void *AThread::loop(void *pData)
{
    std::cout << "Thread Created:" << std::to_string(((AThread *) pData)->mThread) << std::endl;

    ((AThread *) pData)->mLoop = true;

    ((AThread *) pData)->exec();

    ((AThread *) pData)->mThreadStarted = false;

    std::cout << "Thread Terminated:" << std::to_string(((AThread *) pData)->mThread) << std::endl;

    return 0;
}

void AThread::exec()
{
    while(mLoop){
        sleep(1);
        std::cout << "ThreadRunning:" << std::to_string(mThread) << std::endl;
    }
}
