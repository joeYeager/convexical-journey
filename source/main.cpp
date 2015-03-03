// #include "headers/testdata.h"
// #include "headers/timer.h"

#include "headers/runner.h"

int main(int argc, char * argv[]) {

<<<<<<< Updated upstream
    bool verbose = false;
=======
    Runner runner(1, 2000);
    runner.start();

    // TestData test;
    // Timer timer;

    // std::vector< Coordinate > coords;

    // int size = 100000000, bound = 10000;

    // std::cout << "\n=============================================" << std::endl;
    // std::cout << "\n           Example Function Timer" << std::endl;
    // std::cout << "\n=============================================" << std::endl;


    // timer.startTimer();
    // coords = test.generateRandom(size,bound);
    // timer.stopTimer();
    // std::cout << "\ngenerateRandom: \t\t" << timer.getTime() << " ms" << std::endl;



    // timer.startTimer();
    // coords = test.generateHomogeneous(size,bound);
    // timer.stopTimer();
    // std::cout << "\ngenerateHomogeneous: \t\t" << timer.getTime() << " ms"<< std::endl;



    // timer.startTimer();
    // coords = test.generateSorted(size,bound);
    // timer.stopTimer();
    // std::cout << "\ngenerateSorted: \t\t" << timer.getTime() << " ms"<< std::endl;



    // timer.startTimer();
    // coords = test.generateReverseSorted(size,bound);
    // timer.stopTimer();
    // std::cout << "\ngenerateReverseSorted: \t\t" << timer.getTime() << " ms"<< std::endl;



    // timer.startTimer();
    // coords = test.generateCircle(size);
    // timer.stopTimer();
    // std::cout << "\ngenerateCircle: \t\t" << timer.getTime() << " ms\n\n"<< std::endl;
>>>>>>> Stashed changes

    if (argc >= 2 && strcmp(argv[1], "-v") == 0) {
        verbose = true;
    }
    else if (argc >= 2 && strcmp(argv[1], "-v") != 0) {
        std::cout << "Unrecognized argument " << argv[1] << ".\n"
                  << "Acceptable arguments are:\n"
                  << "  -v (verbose) Log to stdout.";
        return 1;
    }

    Runner runner(1, 2000, verbose);
    runner.start();

    return 0;
}