#include "headers/jarvis.h"

std::vector<Coordinate> Jarvis::hull(std::vector<Coordinate> v){
    
    if(v.size() <= 3){
        return v;
    }    

    int l = 0;
    int n = v.size();
    for(int i = 1; i < n; ++i){
        if(v[i].x < v[l].x){
            l = i;
        }
    }

    int p = l;
    int q = p + 1;

    do {
        q = (p + 1)%n;
        for(int i = 0; i < n; ++i){
            if(p!=i && this->orientation(v[p],v[i],v[q]) == 2){
                q=i;
            }
        }
        this->convexHull.push_back(v[q]);
        p = q;
    } while(p != l);
    
    return this->convexHull;

}






