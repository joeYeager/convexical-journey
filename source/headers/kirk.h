#ifndef KIRK_H
#define KIRK_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include "testdata.h"

class Kirk {
    public:
        std::vector<Coordinate> hull(std::vector<Coordinate>);

    private:
        struct sortBy{
            bool ascend;
            sortBy(bool asc) : ascend(asc) {}
            inline bool operator() (const Coordinate& coord1, const Coordinate& coord2){

                if(this->ascend){
                    return (coord1.x < coord2.x);
                }
                else{
                        return (coord1.x > coord2.x);
                }
            }

        };
        std::vector<Coordinate> convexHull;

        void hullHelper(std::vector<Coordinate>);
        std::vector<Coordinate>  bridge(std::vector<Coordinate> v, Coordinate median);
        Coordinate min(std::vector<Coordinate> coords);
        Coordinate max(std::vector<Coordinate> coords);
        Coordinate median(std::vector<Coordinate> coords);
};

#endif /* KIRK_H */