#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include "testdata.h"

class Algorithm {
	public:
		std::string name;
		virtual void sort(std::vector<Coordinate> &points) = 0;
};

#endif /* ALGORITHM_H */