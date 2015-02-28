#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <math.h>

#define TESTDATA_H

struct Coordinate
{
    short int x, y;
    Coordinate(short int px, short int py) : x(px), y(py) {}
};

struct CoordinateFloats
{
    float x, y;
    CoordinateFloats(float px, float py) : x(px), y(py) {}
};

class TestData {
    private:
        // A private variable to hold the pairs of points (x,y)
        std::vector< Coordinate > coords;
        std::vector< CoordinateFloats > coordFloats;

        // Populates coords with randomData
        void populate(int size, int bound);

        // This is a struct with an overloaded () operator, this is used as an overloaded function
        // By std::sort in the TestData::sort function
        // The constructor for this struct takes two arguments, these change the order and coordinate that
        // the data is sorted.  If ascending is true, it will be sorted in ascending order, otherwise descending
        // if sortByX is true, then it will be sorted by x, otherwise sorted by y;
        struct sortBy
            {
                bool ascend;
                bool sortByX;
                sortBy(bool asc, bool x ) : ascend(asc), sortByX(x) {}
                inline bool operator() (const Coordinate& coord1, const Coordinate& coord2){
                        if(this->ascend){
                            if(this->sortByX){
                                return (coord1.x < coord2.x);
                            }
                            else{
                                return (coord1.y < coord2.y);
                            }
                        }
                        else{
                            if(this->sortByX){
                                return (coord1.x > coord2.x);
                            }
                            else{
                                return (coord1.y > coord2.y);
                            }
                        }
                }

        };

        // Sorts the data by the x value, in ascdening order
        void sort();

        // Sorts the data by the x value, in descending order 
        void reverseSort();

    public:
        
        void printPoint(int index);
        void outputPoints();
        void resizeCoords(int size);
        void resizeCoordFloats(int size);
        std::vector< Coordinate > generateRandom(int size, int bound);
        std::vector< Coordinate > generateHomogeneous(int size, int bound);
        std::vector< Coordinate > generateSorted(int size, int bound);
        std::vector< Coordinate > generateReverseSorted(int size, int bound);
        std::vector< CoordinateFloats > generateCircle(int size);

};