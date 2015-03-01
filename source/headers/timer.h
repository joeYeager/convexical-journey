#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

class Timer {
    public:
        void startTimer();
        void stopTimer();
        int getTime();
    private:
        clock_t startTime;
        clock_t endTime;
};

#endif