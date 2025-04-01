#include <time.h>
#include <stdlib.h>

#include "timer.h"

struct timespec ts;

void timer_pause(unsigned jiffies)
{
    clock_t now = clock();
    if (clock() < now + jiffies)
    {
       while(clock() < now + jiffies) { /* wait */ }
    }
}

long timer_getMillis()
{
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_nsec / 1000000;
}
