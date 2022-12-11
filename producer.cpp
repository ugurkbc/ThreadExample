#include "producer.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "shareddata.h"

Producer::Producer(SharedData *pSharedData)
    : mSharedData(pSharedData)
{

}

void Producer::exec()
{
    while(mLoop){
        int randNum = rand() % 100;
        mSharedData->setValue(randNum);
        //usleep(randNum * 1000);
    }
}
