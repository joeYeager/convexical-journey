#include "headers/bruteforce.h"

BruteForce::BruteForce() {
	name = "Brute Force";
	log = "bruteforce.csv";
}

//Starts off the algorithm and returns a
void BruteForce::hull(std::vector<Coordinate> &points) {
	std::vector<Coordinate> hull;
	for(unsigned int i = 0; i < points.size(); ++i) {			//Move through the vector
		Coordinate pointA = points[i];
		if(findPoint(points, pointA) == 1)
			hull.push_back(pointA);
	}
}

//Will compare all points to the point sent in
int BruteForce::findPoint(std::vector<Coordinate> & points, Coordinate & pointA) {
	bool state;
	int changes,loc;
	for(unsigned int i = 0; i < points.size(); ++i) {
		Coordinate pointB = points[i];
		if(!compare(pointA, pointB))
		{
			state = false;
			changes = 0;
			for(unsigned int e = 0; e < points.size(); ++e) {
				Coordinate pointC = points[e];
				if(!compare(pointC, pointA) && !compare(pointC, pointB)) {
					loc = isAbove(pointA, pointB, pointC);
					if(state != loc) {
						state = loc;
						changes += 1;
					}
				}
			}
			if(changes == 1)
				return 1;
		}
	}
	return 0;
}

bool BruteForce::compare(Coordinate & pointA, Coordinate & pointB) {
	if(pointA.x == pointB.x &&
		pointA.y == pointB.y)
		return true;
	return false;
}


//
