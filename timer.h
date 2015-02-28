#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

#define TIMER_H

class Timer {
    public:
        void startTimer();
        void stopTimer();
        int getTime();
    private:
        clock_t startTime;
        clock_t endTime;
};