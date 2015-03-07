#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include "testdata.h"

class Algorithm {

	public:
		std::string name;
		virtual void hull(std::vector<Coordinate> &points) = 0;

	protected:
        struct sortBy{
            bool ascend;
            sortBy(bool asc) : ascend(asc) {}
            inline bool operator() (const Coordinate& coord1, const Coordinate& coord2){

                if(ascend){
                    return (coord1.x < coord2.x);
                }
                else{
                        return (coord1.x > coord2.x);
                }
            }

        };

        std::vector<Coordinate> convexHull;
		Coordinate leftMostCoordinate(std::vector<Coordinate> coords);
        double distance(Coordinate a, Coordinate b, Coordinate c);
		bool isAbove(Coordinate a, Coordinate b, Coordinate c);
        double orientation(Coordinate a, Coordinate b, Coordinate c);
        void clear();
};

#endif /* ALGORITHM_H */
