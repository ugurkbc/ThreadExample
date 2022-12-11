#include "shareddata.h"
#include "producer.h"
#include "consumer.h"

#include <unistd.h>

int main()
{
    SharedData sharedData;
    Producer producer(&sharedData);
    Consumer consumer(&sharedData);

    producer.start();
    sleep(1);
    consumer.start();

    sleep(5);

    producer.quit();
    consumer.quit();

    producer.wait();
    consumer.wait();

    return 0;
}
