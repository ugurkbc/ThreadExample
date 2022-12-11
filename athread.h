#ifndef ATHREAD_H
#define ATHREAD_H

#include <pthread.h>

class AThread
{
public:
    AThread();
    int start();
    int wait();
    void quit();
private:
    static void * loop(void *pData);
protected:
    void virtual exec();
private:
    pthread_t mThread;
    bool mThreadStarted = false;
protected:
    bool mLoop = false;
};

#endif // ATHREAD_H
