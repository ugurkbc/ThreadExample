#ifndef PRODUCER_H
#define PRODUCER_H

#include "athread.h"

class SharedData;

class Producer : public AThread
{
public:
    Producer(SharedData *);
 private:
    SharedData *mSharedData;
protected:
    void exec();
};

#endif // PRODUCER_H
