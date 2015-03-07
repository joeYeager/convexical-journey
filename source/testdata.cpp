#include "headers/testdata.h"

void TestData::populate(int size, int bound){
    if(coords.size() != size){

        // Seed the random number generator
        srand (time(NULL));

        // Iterate through the vector and and create random pairs of positive and negative numbers that are within the
        //  range (-bound, bound)
        while(coords.size() < size){
            double x = ((rand() % (2*bound)+1) - bound);
            double y = ((rand() % (2*bound)+1) - bound);

            coords.push_back( Coordinate(x,y) );
        }
        unique u;
        sort();
        coords.erase(std::unique(coords.begin(),coords.end(),u), coords.end() );
        populate(size,bound);
    }
    
}

void TestData::sort(){
    sortBy compare(true,true);
    std::sort(coords.begin(), coords.end(), compare);
}

void TestData::reverseSort(){
    sortBy compare(false,true);
    std::sort(coords.begin(), coords.end(), compare);
}

void TestData::printPoint(int i){
    if( i >= 0 && i <= coords.capacity()){
        std::cout << "(" << coords[i].x << "," << coords[i].y << ")" << std::endl;
    }
    else{
        std::cout << "Index is out of range\n";
    }
}

void TestData::outputPoints(){
    std::ofstream file;
    file.open ("points.csv");
    for ( int i = 0; i< coords.size(); ++i ){

          std::cout << coords[i].x << "," << coords[i].y << "\n";

    }
    file.close();
}

void TestData::resizeCoords(int size){
    coords.clear();
    coords.reserve(size);
}


std::vector< Coordinate > TestData::generateRandom(int size, int bound){
    resizeCoords(size);
    std::random_shuffle(coords.begin(),coords.end());
    populate(size,bound);
    return coords;
}

std::vector< Coordinate > TestData::generateHomogeneous(int size, int bound){

    resizeCoords(size);

    // Resize the vector to the desired size

    // Seed the random number generator
    srand (time(NULL));

    short int x = ((rand() % (2*bound)+1) - bound);
    short int y = ((rand() % (2*bound)+1) - bound);

    // Iterate through the vector and and create random pairs of positive and negative numbers that are within the
    //  range (-bound, bound)
    for(int j = 0; j < size; ++j){
        coords.push_back( Coordinate(x,y) );
    }
    return coords;
}

std::vector< Coordinate > TestData::generateSorted(int size, int bound){
    populate(size,bound);
    sort();
    return coords;
}

std::vector< Coordinate >TestData::generateReverseSorted(int size, int bound){
    populate(size,bound);
    reverseSort();
    return coords;
}

std::vector< Coordinate >TestData::generateCircle(int size){
    resizeCoords(0);

    double radius = (double)size/(double)100;
    double incrementor = ((M_PI * 2)/(double)size);
    // double x,y;
    for(double j = 0; j < 2*M_PI; j+=incrementor){
        coords.push_back( Coordinate(0 + radius*cos(j),0 + radius*sin(j)) );
    }

    return coords;
}

