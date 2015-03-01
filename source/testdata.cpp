#include "headers/testdata.h"

void TestData::populate(int size, int bound){

    this->resizeCoords(size);
    this->resizeCoordFloats(0);

    // Seed the random number generator
    srand (time(NULL));

    // Iterate through the vector and and create random pairs of positive and negative numbers that are within the
    //  range (-bound, bound)
    for(int j = 0; j < size; ++j){
        short int x = ((rand() % (2*bound)+1) - bound);
        short int y = ((rand() % (2*bound)+1) - bound);

        this->coords.push_back( Coordinate(x,y) );
    }

}

void TestData::sort(){
    sortBy compare(true,true);
    std::sort(this->coords.begin(), this->coords.end(), compare);
}

void TestData::reverseSort(){
    sortBy compare(false,true);
    std::sort(this->coords.begin(), this->coords.end(), compare);
}

void TestData::printPoint(int i){
    if( i >= 0 && i <= this->coords.capacity()){
        std::cout << "(" << this->coords[i].x << "," << this->coords[i].y << ")" << std::endl;
    }
    else{
        std::cout << "Index is out of range\n";
    }
}

void TestData::outputPoints(){
    std::ofstream file;
    file.open ("points.csv");
    for ( int i = 0; i< this->coordFloats.size(); ++i ){

          file << this->coordFloats[i].x << "," << this->coordFloats[i].y << "\n";

    }
    file.close();
}

void TestData::resizeCoords(int size){
    this->coords.clear();
    this->coords.reserve(size);
}

void TestData::resizeCoordFloats(int size){
    this->coordFloats.clear();
    this->coordFloats.reserve(size);
}

std::vector< Coordinate > TestData::generateRandom(int size, int bound){
    this->populate(size,bound);
    return this->coords;
}

std::vector< Coordinate > TestData::generateHomogeneous(int size, int bound){

    this->resizeCoords(size);
    this->resizeCoordFloats(0);

    // Resize the vector to the desired size

    // Seed the random number generator
    srand (time(NULL));

    short int x = ((rand() % (2*bound)+1) - bound);
    short int y = ((rand() % (2*bound)+1) - bound);

    // Iterate through the vector and and create random pairs of positive and negative numbers that are within the
    //  range (-bound, bound)
    for(int j = 0; j < size; ++j){
        this->coords.push_back( Coordinate(x,y) );
    }
    return this->coords;
}

std::vector< Coordinate > TestData::generateSorted(int size, int bound){
    this->populate(size,bound);
    this->sort();
    return this->coords;
}

std::vector< Coordinate >TestData::generateReverseSorted(int size, int bound){
    this->populate(size,bound);
    this->reverseSort();
    return this->coords;
}

std::vector< CoordinateFloats >TestData::generateCircle(int size){
    this->resizeCoords(0);
    this->resizeCoordFloats(size);

    double radius = (double)size/(double)100;
    double incrementor = ((M_PI * 2)/(double)size);
    // double x,y;
    for(double j = 0; j < 2*M_PI; j+=incrementor){
        this->coordFloats.push_back( CoordinateFloats(0 + radius*cos(j),0 + radius*sin(j)) );
    }

    return this->coordFloats;
}

