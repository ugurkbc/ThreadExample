#ifndef CONSUMER_H
#define CONSUMER_H

#include "athread.h"

class SharedData;

class Consumer : public AThread
{
public:
    Consumer(SharedData *);
private:
   SharedData *mSharedData;
protected:
    void exec();
};

#endif // CONSUMER_H
