// #include "headers/testdata.h"
// #include "headers/timer.h"

#include "headers/runner.h"

int main(int argc, char * argv[]) {

    bool verbose = false;

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