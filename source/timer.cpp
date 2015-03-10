#include "headers/timer.h"

void Timer::startTimer(){
    this->startTime = clock();
}

void Timer::stopTimer(){
    this->endTime = clock();
}

float Timer::getTime(){
    clock_t total =  (float)(this->endTime - this->startTime);
    return (float) (( (float)total / (float)CLOCKS_PER_SEC) * 1000.00);
}