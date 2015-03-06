#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "algorithm.h"

class BruteForce : public Algorithm {
	public:
		BruteForce();
		void hull(std::vector<Coordinate> &points);
	protected:
		int findPoint(std::vector<Coordinate> & points, Coordinate & point);
		bool compare(Coordinate & pointA, Coordinate & pointB);
			
};

#endif /* BRUTEFORCE.H */
