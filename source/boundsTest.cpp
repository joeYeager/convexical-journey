#include "headers/runner.h"
#include <string>
#include <vector>

int main(int argc, char * argv[]) {

    TestData test;
    Timer timer;

    QuickHull quick;
    Jarvis jarvis;
    BruteForce brute;

    int size = 50000;
    std::vector<Coordinate> v = test.generateRandom(size,100000);
    std::cout <<"Starting testing\n";
    std::vector<Coordinate> t1 = v;
    std::vector<Coordinate> t2 = v;
    std::vector<Coordinate> t3 = v;

    // std::cout << "\nRandom\n\n";

    // timer.startTimer();
    // quick.hull(t1);
    // timer.stopTimer();
    // std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    // timer.startTimer();
    // jarvis.hull(t2);
    // timer.stopTimer();
    // std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;


    // v = test.generateSorted(size,100000);
    // std::cout <<"Starting testing\n";
    // t1 = v;
    // t2 = v;
    // t3 = v;

    // std::cout << "\nSorted\n\n";

    // timer.startTimer();
    // quick.hull(t1);
    // timer.stopTimer();
    // std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    // timer.startTimer();
    // jarvis.hull(t2);
    // timer.stopTimer();
    // std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;

    // v = test.generateReverseSorted(size,100000);
    // std::cout <<"Starting testing\n";
    // t1 = v;
    // t2 = v;
    // t3 = v;

    // std::cout << "\nReverse Sorted\n\n";

    // timer.startTimer();
    // quick.hull(t1);
    // timer.stopTimer();
    // std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    // timer.startTimer();
    // jarvis.hull(t2);
    // timer.stopTimer();
    // std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;

    v = test.generateCircle(size);
    std::cout <<"Starting testing\n";
    t1 = v;
    t2 = v;
    t3 = v;

    std::cout << "\nCircle\n\n";

    timer.startTimer();
    quick.hull(t1);
    timer.stopTimer();
    std::vector<Coordinate> result = quick.getHull();
    std::cout << "Result size: "  << result.size() << std::endl;
    std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    timer.startTimer();
    jarvis.hull(t2);
    timer.stopTimer();
    result = jarvis.getHull();
    std::cout << "Result size: "  << result.size() << std::endl;
    std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    timer.startTimer();
    brute.hull(t3);
    timer.stopTimer();
    std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;


    std::cout << "\n\nDone\n";


}


