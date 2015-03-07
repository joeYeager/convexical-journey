#include "headers/jarvis.h"

void Jarvis::hull(std::vector<Coordinate> & v){

    if(v.size() <= 3){
        for(unsigned int i = 0; i < v.size(); ++i){
            convexHull.push_back(v[i]);
        }
    }    
    else{
        int l = 0;
        int n = v.size();

        for(int i = 1; i < n; ++i){
            if(v[i].x < v[l].x){
                    l = i;
            }
            else if(v[i].x == v[l].x){
                if(v[i].y < v[l].y){
                    l = i;
                }
            }
        }

        int p = l;
        int q = p + 1;
        do {
            convexHull.push_back(v[p]);
            q = (p + 1)%n;

            for(int i = 0; i < n; ++i){
                if(p!=i && (orientation(v[p],v[q],v[i]) > 0 || ( orientation(v[p],v[q],v[i]) == 0 && dist(v[p], v[i]) > dist(v[p], v[q]) ) ) ){
                    q=i;
                }

            }
            p = q;

        } while(p != l);
    } 

}

std::vector<Coordinate> Jarvis::getHull(){
    sortBy compare(true);
    std::vector<Coordinate> v = convexHull;
    std::sort(v.begin(), v.end(),compare);
    clear();
    return v;
}

double Jarvis::dist(Coordinate p, Coordinate q){
    return (q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y);
}
void Jarvis::clear(){
    convexHull.clear();
    convexHull.reserve(0);
}




