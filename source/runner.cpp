#include "headers/runner.h"

Runner::Runner(int min, int max, bool stdlog) {

	bounds = 10000;
	multiplier = 2.0;  // 200% increase
	runsCompleted = 0;
	verbose = stdlog;
	curSampleSize = min;
	minSampleSize = min;
	maxSampleSize = max;
}

void Runner::start() {

	char date[5] = "date";

	curSampleSize = minSampleSize;
	std::vector <Coordinate> coords;
	TestData data;

	BruteForce bruteforce;
	QuickHull quickhull;
	Jarvis jarvis;

	std::cout << "\n==========================================\n";
	std::cout << "\n           Convex Hull Analyzer           \n";
	std::cout << "\n====== "  <<   exec(date)   <<  " ======\n\n";

	while (curSampleSize <= maxSampleSize) {

		std::vector <Coordinate> random, homogeneous, sorted, reverse, circular;

		random = data.generateRandom(curSampleSize, bounds);
		sorted = data.generateSorted(curSampleSize, bounds);
		reverse = data.generateReverseSorted(curSampleSize, bounds);
		circular = data.generateCircle(curSampleSize);

		for (int i = 0; i < 5; ++i) {

			// Quick Hull Algorithm
			save(test(quickhull, random, "random"));
			save(test(quickhull, sorted, "sorted"));
			save(test(quickhull, reverse, "reverse"));
			save(test(quickhull, circular, "circular"));

			// Jarvis March Algorithm
			save(test(jarvis, random, "random"));
			save(test(jarvis, sorted, "sorted"));
			save(test(jarvis, reverse, "reverse"));
			if (curSampleSize <= 100000) { // takes too long after 100k points
				save(test(jarvis, circular, "circular"));
			}

			// Brute Force Algorithm
			if (curSampleSize <= 100000) { // takes too long after 100k points
				save(test(bruteforce, random, "random"));
				save(test(bruteforce, sorted, "sorted"));
				save(test(bruteforce, reverse, "reverse"));
				save(test(bruteforce, circular, "circular"));
			}
		}

		curSampleSize = increaseSampleSize(curSampleSize);
	}
}

int Runner::increaseSampleSize(int current) {

	int next = 0;

	if (current == maxSampleSize) {
		next = maxSampleSize + 1; // push sample size over the limit
	}
	else {

		next = current * multiplier; // currently doubles

		if (next > maxSampleSize) {
			next = maxSampleSize; // do one more run at max sample size
		}
	}

	return next;
}

Run Runner::test(Algorithm & alg, std::vector <Coordinate> data, std::string ordering) {

	Run run;
	Timer timer;
	float delta;

	timer.startTimer();
	alg.hull(data);
	timer.stopTimer();

	delta = timer.getTime();

	run.algorithm = alg.name;
	run.size = curSampleSize;
	run.type = ordering;
	run.log = alg.log;
	run.time = delta;

	return run;
}

void Runner::save(Run run) {

	char date[5] = "date";
	logfile.open("records/" + run.log, std::ios::app);

	++runsCompleted;

    logfile << run.size << "," << run.time << "," << run.type << "\n";

	if (verbose) {
		std::cout << "( " + std::to_string(runsCompleted) + " ) "
        	+ run.algorithm + " on " + std::to_string(run.size) + " " + run.type + " points.\n"
        	+ "[ " + std::to_string(run.time) + "ms ] @ " + exec(date) + "\n\n";
	}

	logfile.close();
}

std::string Runner::exec(char * cmd) {

    FILE * pipe = popen(cmd, "r");
    std::string result = "";
    char buffer[128];

    if (!pipe) return "ERROR";

    while (!feof(pipe)) {

    	if (fgets(buffer, 128, pipe) != NULL) {
    		result += buffer;
    	}
    }

    pclose(pipe);

    if (result[result.size() - 1] == '\n') {
    	result.erase(result.size() - 1);
    }

    return result;
}
