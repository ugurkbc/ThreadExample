#include "consumer.h"
#include "shareddata.h"
#include <iostream>

Consumer::Consumer(SharedData *pSharedData)
    : mSharedData(pSharedData)
{

}

void Consumer::exec()
{
    while(mLoop){
       mSharedData->getValue();
    }
}
