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
        std::vector<Coordinate> hull(std::vector<Coordinate> v);

    private:
        std::vector<Coordinate> convexHull;
};

#endif /* Jarvis_H */