#ifndef RUNNER_H
#define RUNNER_H

#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>

#include "testdata.h"
#include "timer.h"

struct Run {
	int time;
	int size;
	std::string type;
	std::string algorithm;
};

class Runner {

	public:
		Runner(int min, int max, bool stdlog);

		void start();

	private:
		bool verbose;
		int curSampleSize;
		int minSampleSize;
		int maxSampleSize;
		int bounds;
		int interval;
		int runsCompleted;
		int totalRuns;
		std::ofstream logfile;


		Run BruteForceHull(std::vector <Coordinate> data, std::string ordering);
		// Run QuickHull(std::vector <Coordinate> data, string ordering);
		// Run UltimatePlanar(std::vector <Coordinate> data, string ordering);

		void banner();
		void save(Run run);
		std::string exec(char * cmd);
};

#endif /* RUNNER_H */