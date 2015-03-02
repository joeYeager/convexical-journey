#ifndef RUNNER_H
#define RUNNER_H

#include "testdata.h"
#include "timer.h"

#include <string>
#include <math.h>
#include <stdlib.h>

struct Run {
	int time;
	int size;
	std::string type;
	std::string algorithm;
};

class Runner {

	public:
		Runner(int min, int max);

		void start();

	private:
		int curSampleSize;
		int minSampleSize;
		int maxSampleSize;
		int bounds;
		int interval;
		int runsCompleted;
		int totalRuns;

		void save(Run run);
		Run BruteForceHull(std::vector <Coordinate> data, std::string ordering);
		// Run QuickHull(std::vector <Coordinate> data, string ordering);
		// Run UltimatePlanar(std::vector <Coordinate> data, string ordering);
};

#endif /* RUNNER_H */