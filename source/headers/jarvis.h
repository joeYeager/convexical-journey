#ifndef JARVIS_H
#define JARVIS_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "algorithm.h"
#include "testdata.h"

class Jarvis: public Algorithm {
    public:
        void hull(std::vector<Coordinate> & v);
        std::vector<Coordinate> getHull();
    private:
        
        std::vector<Coordinate> convexHull;

        double dist(Coordinate p, Coordinate q);
        void clear();
};

#endif /* JARVIS_H */
