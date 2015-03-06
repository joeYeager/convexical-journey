#include "headers/bruteforce.h"

BruteForce::BruteForce() {
	name = "Brute Force";
}

//Starts off the algorithm and returns a
void BruteForce::hull(std::vector<Coordinate> &points) {
	std::vector<Coordinate> hull;
	for(int i = 0; i < points.size(); ++i) {			//Move through the list
		Coordinate pointA = points[i];
		if(findPoint(points, pointA) == 1)
			hull.push_back(pointA);	
	}
}

//Will compare all points to the point sent in
int BruteForce::findPoint(std::vector<Coordinate> & points, Coordinate & pointA) {
	for(int i = 0; i < points.size(); ++i) {
		Coordinate pointB = points[i];
		if(!compare(pointA, pointB)) 
		{
			bool state = false;
			int changes = 0;
			for(int e = 0; e < points.size(); ++e) {
				Coordinate pointC = points[e];
				if(!compare(pointC, pointA) && !compare(pointC, pointB)) {
					int loc = isAbove(pointA, pointB, pointC);
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
		return 1;
	return 0;
}


//
