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

        void clear();
        double dist(Coordinate p, Coordinate q);

};

#endif /* JARVIS_H */
