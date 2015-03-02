#include "headers/runner.h"

Runner::Runner(int min, int max) {

	curSampleSize = min;
	minSampleSize = min;
	maxSampleSize = max;
	bounds = 10000;
	interval = 500;
	runsCompleted = 0;
	// TODO - this should be "* 6" once circular is fixed
	totalRuns = ceil(maxSampleSize/interval) * 5;
}

void Runner::start() {

	curSampleSize = minSampleSize;
	std::vector <Coordinate> coords;
    std::vector <CoordinateFloats> coordFloats;
	TestData data;

    std::cout << "\n=========================================\n";
	std::cout << "\n           Convex Hull Analyzer          \n";
	std::cout << "\n=========================================\n";

	while (curSampleSize <= maxSampleSize) {

		std::vector <Coordinate> random, homogeneous, sorted, reverse;
    	std::vector <CoordinateFloats> circular;

		random = data.generateRandom(curSampleSize, bounds);
		homogeneous = data.generateHomogeneous(curSampleSize, bounds);
		sorted = data.generateSorted(curSampleSize, bounds);
		reverse = data.generateReverseSorted(curSampleSize, bounds);
		circular = data.generateCircle(curSampleSize);

		// Ultimate Planar Convex Hull Algorithm
		// save(UltimatePlanar(random));
		// save(UltimatePlanar(homogeneous));
		// save(UltimatePlanar(sorted));
		// save(UltimatePlanar(reverse));
		// save(UltimatePlanar(circular));

		// Quick Hull Algorithm
		// save(QuickHull(random));
		// save(QuickHull(homogeneous));
		// save(QuickHull(sorted));
		// save(QuickHull(reverse));
		// save(QuickHull(circular));

		// Brute Force Algorithm
		save(BruteForceHull(random, "random"));
		save(BruteForceHull(homogeneous, "uniform"));
		save(BruteForceHull(sorted, "sorted"));
		save(BruteForceHull(reverse, "reverse"));
		// save(BruteForceHull(circular, "circular"));

		if (curSampleSize == maxSampleSize) {
			curSampleSize += 1; // push sample size over the limit and exit
		}
		else if (curSampleSize + interval > maxSampleSize) {
			curSampleSize = maxSampleSize; // do one more run at max sample size
		}
		else {
			curSampleSize += interval; // increase sample size
		}
	}
}

void Runner::save(Run run) {

	std::string msg = "(" + std::to_string(++runsCompleted) + " of " + std::to_string(totalRuns) + ")\t"
        + run.algorithm + " on " + run.type + "\t"
        + "  [ " + std::to_string(run.size) + " coords in " + std::to_string(run.time) + "ms ]\n";

	// Log to stdout
	std::cout << msg;

	// Log to file
	// TODO

	// Save to database
	// TODO
}

Run Runner::BruteForceHull(std::vector <Coordinate> data, std::string ordering) {

	Run run;
	Timer timer;

	timer.startTimer();

	// TODO - implement brute hull algorithm

	timer.stopTimer();

	run.time = timer.getTime();
	run.size = curSampleSize;
	run.type = ordering;
	run.algorithm = "bruteforce";

	return run;
}

// Run Runner::BruteForceHull(vector <Coordinate> data) {
// 	//
// }

// Run Runner::BruteForceHull(vector <Coordinate> data) {
// 	//
// }