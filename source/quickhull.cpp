#include "headers/quickhull.h"

QuickHull::QuickHull() {
	name = "Quick Hull";
}

void QuickHull::hull(std::vector<Coordinate> &v) {
    int l = 0;
    int r = 0;
    int n = v.size();


    for(int i = 1; i < n; ++i){
        if(v[i].x < v[l].x){
                l = i;
        }
        else if(v[i].x > v[l].x){
                r = i;
        }
        else if(v[i].x == v[l].x){
            if(v[i].y < v[l].y){
                l = i;
            }
            else if(v[i].y > v[l].y){
                r = i;
            }
        }

    }

    Coordinate A(v[l].x,v[l].y);
    Coordinate B(v[r].x,v[r].y);
    
    convexHull.push_back(A);
    convexHull.push_back(B);
    

    // Tombstone the values
    v[l].x = -123456789;
    v[r].x = -123456789;


    std::vector<Coordinate> above;
    std::vector<Coordinate> below;

    for(int i = 0; i < v.size(); ++i) {
        if(v[i].x != -123456789){
            if(location(A, B, v[i]) == -1){
                above.push_back(v[i]);
            }
            else{
                below.push_back(v[i]);
            }
        }
    }

    findHull (above, A, B);
    findHull (below, B, A);


}


void QuickHull::findHull(std::vector<Coordinate> &sk, Coordinate P, Coordinate Q){

    if(sk.size() != 0){

        double max = 0;
        int loc = 0;
        for(int i = 0; i < sk.size(); ++i){
            if( distance( P, Q, sk[i] ) > max){
                max = distance( P, Q, sk[i] );
                loc = i;
            }
        }
        Coordinate C = Coordinate(sk[loc].x, sk[loc].y);
        convexHull.push_back(sk[loc]);
        sk.erase(sk.begin()+loc);
        std::vector<Coordinate> leftCQ, leftPC;
       
        for (int i = 0; i < sk.size(); ++i) {
            if(sk[i].x != -123456789){
                if (location(C,Q,sk[i])==1) {
                  leftCQ.push_back(sk[i]);
                  sk[i].x = -123456789; // Tombstone
                }
                else if (location(P,C,sk[i])==1) {
                  leftPC.push_back(sk[i]);
                  sk[i].x = -123456789; // Tombstone
                } 
            }    
        }

        findHull(leftPC,P,C);
        findHull(leftCQ,C,Q);

    }
}

int QuickHull::location(Coordinate A, Coordinate B, Coordinate C) {
    double num = ((B.x - A.x) * (A.y-C.y)) - ((B.y - A.y) * (A.x-C.x));
    return (num>0) ? 1 : -1; //Returns the location
}

std::vector<Coordinate> QuickHull::getHull(){
    sortBy compare(true);
    std::vector<Coordinate> v = convexHull;
    std::sort(v.begin(), v.end(),compare);
    clear();
    return v;
}

void QuickHull::clear(){
    convexHull.clear();
    convexHull.reserve(0);
}