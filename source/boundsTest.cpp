#include "headers/runner.h"
#include <string>
#include <vector>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>

BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian);
std::vector<Coordinate> testFun(std::vector<Coordinate> & v);




int main(int argc, char * argv[]) {

    TestData test;
    Timer timer;

    QuickHull quick;
    Jarvis jarvis;
    BruteForce brute;

    int size = 50000;
    std::vector<Coordinate> v = test.generateRandom(size,10000);
    std::cout <<"Starting testing\n";
    std::vector<Coordinate> t1 = v;
    std::vector<Coordinate> t2 = v;
    std::vector<Coordinate> t3 = v;

    std::cout << "\nRandom\n\n";

    timer.startTimer();
    quick.hull(t1);
    timer.stopTimer();
    std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    timer.startTimer();
    jarvis.hull(t2);
    timer.stopTimer();
    std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;


    v = test.generateSorted(size,10000);
    std::cout <<"Starting testing\n";
    t1 = v;
    t2 = v;
    t3 = v;

    std::cout << "\nSorted\n\n";

    timer.startTimer();
    quick.hull(t1);
    timer.stopTimer();
    std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    timer.startTimer();
    jarvis.hull(t2);
    timer.stopTimer();
    std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;

    v = test.generateReverseSorted(size,10000);
    std::cout <<"Starting testing\n";
    t1 = v;
    t2 = v;
    t3 = v;

    std::cout << "\nReverse Sorted\n\n";

    timer.startTimer();
    quick.hull(t1);
    timer.stopTimer();
    std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    timer.startTimer();
    jarvis.hull(t2);
    timer.stopTimer();
    std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;

    v = test.generateCircle(size);
    std::cout <<"Starting testing\n";
    t1 = v;
    t2 = v;
    t3 = v;

    // std::cout << "\nCircle\n\n";

    // timer.startTimer();
    // quick.hull(t1);
    // timer.stopTimer();
    // std::cout << "Quickhull Time Taken: " << timer.getTime() << std::endl;

    // timer.startTimer();
    // jarvis.hull(t2);
    // timer.stopTimer();
    // std::cout << "Jarvis Time Taken: " << timer.getTime() << std::endl;
    
    // timer.startTimer();
    // brute.hull(t3);
    // timer.stopTimer();
    // std::cout << "Brute Force Time Taken: " << timer.getTime() << std::endl;


    std::cout << "\n\nDone\n";


}


std::vector<Coordinate> testFun(std::vector<Coordinate> & v)
{
    typedef boost::tuple<double, double> point;
    typedef boost::geometry::model::multi_point<point> polygon;

    polygon poly;

    std::string polyStr = "multipoint(";
    for(int i = 0; i < v.size(); ++i){
         polyStr.append(std::to_string(v[i].x));
         polyStr.append(" ");
         polyStr.append(std::to_string(v[i].y));
         if( i !=  v.size() -1){
            polyStr.append(", ");
         }

    }
    polyStr.append(")");

    boost::geometry::read_wkt(polyStr, poly);

    polygon hull;
    boost::geometry::convex_hull(poly, hull);
    
    std::vector<Coordinate> r;

    using boost::geometry::get;

    for (  auto hullIterator = hull.begin();
          hullIterator != hull.end();
          ++hullIterator )
    {
         // for vectors of x and y, extract the x/y from the point
        r.push_back(Coordinate(get<0>( *hullIterator ),get<1>( *hullIterator )) );

    }
    r.shrink_to_fit();
    r.pop_back(); // Boost inlcudes the starting point as the ending point


    return r;

}
