#include "timer.h"

void Timer::startTimer(){
    this->startTime = clock();
}

void Timer::stopTimer(){
    this->endTime = clock();
}

int Timer::getTime(){
    clock_t total =  (float)(this->endTime - this->startTime);
    return (int) (( (float)total / CLOCKS_PER_SEC) * 1000);
}