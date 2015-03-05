#include "headers/runner.h"

Runner::Runner(int min, int max, bool stdlog) {

	bounds = 10000;
	interval = 500;
	runsCompleted = 0;
	verbose = stdlog;
	curSampleSize = min;
	minSampleSize = min;
	maxSampleSize = max;
	totalRuns = ceil(maxSampleSize/interval) * 5; // TODO - this should be "* 6" once circular is fixed
}

void Runner::start() {

	curSampleSize = minSampleSize;
	std::vector <Coordinate> coords;
	TestData data;

	logfile.open("log.txt", std::ios::app);

    banner();

	while (curSampleSize <= maxSampleSize) {

		std::vector <Coordinate> random, homogeneous, sorted, reverse, circular;

		QuickHull quickhull;

		random = data.generateRandom(curSampleSize, bounds);
		homogeneous = data.generateHomogeneous(curSampleSize, bounds);
		sorted = data.generateSorted(curSampleSize, bounds);
		reverse = data.generateReverseSorted(curSampleSize, bounds);
		circular = data.generateCircle(curSampleSize);

		// Ultimate Planar Convex Hull Algorithm
		// save(test(ultimate, random, "random"));
		// save(test(ultimate, homogeneous, "uniform"));
		// save(test(ultimate, sorted, "sorted"));
		// save(test(ultimate, reverse, "reverse"));
		// save(test(ultimate, reverse, "circular"));

		// Quick Hull Algorithm
		save(test(quickhull, random, "random"));
		save(test(quickhull, homogeneous, "uniform"));
		save(test(quickhull, sorted, "sorted"));
		save(test(quickhull, reverse, "reverse"));
		save(test(quickhull, reverse, "circular"));

		// Brute Force Algorithm
		// save(test(bruteforce, random, "random"));
		// save(test(bruteforce, homogeneous, "uniform"));
		// save(test(bruteforce, sorted, "sorted"));
		// save(test(bruteforce, reverse, "reverse"));
		// save(test(bruteforce, reverse, "circular"));

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

	logfile.close();
}

Run Runner::test(Algorithm alg, std::vector <Coordinate> data, std::string ordering) {

	Run run;
	Timer timer;

	timer.startTimer();
	// alg.sort(data);
	timer.stopTimer();

	run.time = timer.getTime();
	run.size = curSampleSize;
	run.type = ordering;
	run.algorithm = alg.name;

	return run;
}

void Runner::banner() {

	char date[5] = "date";

	if (verbose == true) {

		std::cout << "\n==========================================\n";
		std::cout << "\n           Convex Hull Analyzer           \n";
		std::cout << "\n====== "  <<   exec(date)   <<  " ======\n\n";
	}

	logfile   << "\n==========================================\n";
	logfile   << "\n           Convex Hull Analyzer           \n";
	logfile   << "\n====== "  <<   exec(date)   <<  " ======\n\n";
}

void Runner::save(Run run) {

	char date[5] = "date";

    std::string msg = "(" + std::to_string(++runsCompleted) + " of " + std::to_string(totalRuns) + ") "
        + run.algorithm + " on " + std::to_string(run.size) + " " + run.type + " points.\n"
        + "[ " + std::to_string(run.time) + "ms ] @ " + exec(date) + "\n\n";


	if (verbose) std::cout << msg;

	logfile << msg;

	// Save to database
	// TODO
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
