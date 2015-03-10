#ifndef RUNNER_H
#define RUNNER_H

#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>

#include "quickhull.h"
#include "bruteforce.h"
#include "jarvis.h"
#include "testdata.h"
#include "timer.h"

struct Run {
	int size;
	float time;
	std::string log;
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
		int runsCompleted;
		float multiplier;
		std::ofstream logfile;

		int increaseSampleSize(int current);
		Run test(Algorithm & alg, std::vector <Coordinate> data, std::string ordering);

		void banner();
		void save(Run run);
		std::string exec(char * cmd);
};

#endif /* RUNNER_H */
