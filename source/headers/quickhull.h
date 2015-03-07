#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "algorithm.h"

class QuickHull : public Algorithm {

	public:
		QuickHull();
		void hull(std::vector<Coordinate> &points);
		void first();
		void next();
        std::vector<Coordinate> getHull();
    private:
        std::vector<Coordinate> convexHull;
        int location(Coordinate A, Coordinate B, Coordinate C);
        void findHull(std::vector<Coordinate> &sk, Coordinate P, Coordinate Q);
        void clear();
};

#endif /* QUICKHULL_H */
