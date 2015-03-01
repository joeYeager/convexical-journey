#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <math.h>

#include "headers/testdata.h"
#include "headers/timer.h"

int main() {

    TestData test;
    Timer timer;

    std::vector< Coordinate > coords;
    std::vector< CoordinateFloats > coordFloats;

    int size = 1000000, bound = 10000;

    std::cout << "\n=============================================" << std::endl;
    std::cout << "\n           Example Function Timer" << std::endl;
    std::cout << "\n=============================================" << std::endl;


    timer.startTimer();
    coords = test.generateRandom(size,bound);
    timer.stopTimer();
    std::cout << "\ngenerateRandom: \t\t" << timer.getTime() << " ms"<< std::endl;



    timer.startTimer();
    coords = test.generateHomogeneous(size,bound);
    timer.stopTimer();
    std::cout << "\ngenerateHomogeneous: \t\t" << timer.getTime() << " ms"<< std::endl;



    timer.startTimer();
    coords = test.generateSorted(size,bound);
    timer.stopTimer();
    std::cout << "\ngenerateSorted: \t\t" << timer.getTime() << " ms"<< std::endl;



    timer.startTimer();
    coords = test.generateReverseSorted(size,bound);
    timer.stopTimer();
    std::cout << "\ngenerateReverseSorted: \t\t" << timer.getTime() << " ms"<< std::endl;



    timer.startTimer();
    coordFloats = test.generateCircle(size);
    timer.stopTimer();
    std::cout << "\ngenerateCircle: \t\t" << timer.getTime() << " ms\n\n"<< std::endl;



    return 0;
}