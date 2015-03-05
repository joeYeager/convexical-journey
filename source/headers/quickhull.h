#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "algorithm.h"

class QuickHull : public Algorithm {
	public:
		QuickHull();
		void sort(std::vector<Coordinate> &points);
		void first();
		void next();
};

#endif /* QUICKHULL_H */