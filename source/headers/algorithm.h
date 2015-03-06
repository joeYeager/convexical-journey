#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include "testdata.h"

class Algorithm {

	public:
		std::string name;
		virtual void hull(std::vector<Coordinate> &points) = 0;

	protected:
		Coordinate leftMostCoordinate(std::vector<Coordinate> coords);
		int distance(Coordinate a, Coordinate b, Coordinate c);
		bool isAbove(Coordinate a, Coordinate b, Coordinate c);
};

#endif /* ALGORITHM_H */
