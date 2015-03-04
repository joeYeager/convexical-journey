#include "headers/kirk.h"

std::vector<Coordinate> Kirk::hull(std::vector<Coordinate> v){
    this->hullHelper(v);
    return this->convexHull;
}

void Kirk::hullHelper(std::vector<Coordinate> v){
    Coordinate median = this->median(v);
    std::vector<Coordinate> b = this->bridge(v,median);
    std::vector<Coordinate> left,right;
    
    Coordinate min = this->min(v);
    Coordinate max = this->max(v);
    
    for(int i = 0; i < v.capacity(); ++i){
        if(v[i].x <= b[0].x){
            left.push_back(Coordinate(b[0].x,b[0].y));
        }
        else if(v[i].x >= b[1].x){
            right.push_back(Coordinate(b[1].x,b[1].y));   
        }
    }

    if(b[0].x == min.x && b[0].y == min.y){
        this->convexHull.push_back(min);
    }
    else{
        hullHelper(left);
    }

    if(b[1].x == max.x && b[1].y == max.y){
        this->convexHull.push_back(max);
    }
    else{
        hullHelper(right);
    }

}

std::vector<Coordinate> Kirk::bridge(std::vector<Coordinate> v, Coordinate median){
    if(v.size() == 2){
        return v;
    }
}

Coordinate Kirk::min(std::vector<Coordinate> coords){
    
    sortBy compare(true);
    std::vector< Coordinate > v = coords;

    std::nth_element(v.begin(), v.begin(), v.end(),compare);

    double x = v[0].x, y = v[0].y;
    return Coordinate(x,y);

}

Coordinate Kirk::max(std::vector<Coordinate> coords){
    
    sortBy compare(false);
    std::vector< Coordinate > v = coords;

    std::nth_element(v.begin(), v.begin(), v.end(),compare);

    double x = v[0].x, y = v[0].y;
    return Coordinate(x,y);

}
Coordinate Kirk::median(std::vector<Coordinate> coords){
    
    sortBy compare(true);
    int medianIndex = ceil((double)coords.size()/2.0);
    std::vector< Coordinate > v = coords;

    std::nth_element(v.begin(), v.begin() + medianIndex, v.end(),compare);

    double x = v[medianIndex-1].x, y = v[medianIndex-1].y;
    return Coordinate(x,y);

}


