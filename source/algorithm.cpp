#include "headers/algorithm.h"

/**
 * Returns the coordinate with the least x-value.
 * Assumes the vector has at least one element.
*/
Coordinate Algorithm::leftMostCoordinate(std::vector<Coordinate> coords) {

	int min = coords[0].x;
	int minIndex = 0;

	for (int i = 0; i < coords.size(); ++i) {
		if (coords[i].x < min) {
			minIndex = i;
		}
	}

	return coords[minIndex];
}

/**
 * Form a line using Coordinates "a" and "b", then find the distance of the
 * coordinate "c" from the line "ab".
*/
double Algorithm::distance(Coordinate a, Coordinate b, Coordinate c) {
	double num = (((b.x - a.x) * (a.y - c.y)) - ((b.y - a.y) * (a.x - c.x)));
	return (num < 0 ? -num : num);
}

/**
 * Returns whether or not a coordinate "c" is "above" a line formed by the
 * coordinates "a" and "b". The term "above" is a little arbitrary, but this
 * function is used to determine whether a group of coordinates ("c") are on
 * the SAME side of a line ("ab"). So which side is "above" doesn't matter,
 * so long as we can determine similarity or difference.
*/
bool Algorithm::isAbove(Coordinate a, Coordinate b, Coordinate c) {

	int above = distance(a, b, c);
	return (above < 0 ? false : true);
}

double Algorithm::orientation(Coordinate p, Coordinate q, Coordinate r){
    return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

void Algorithm::clear(){
    convexHull.clear();
    convexHull.reserve(0);
}