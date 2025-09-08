#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(4,4);
    Point b(6,1);
    Point c(1,1);

    std::cout << "(4,2) is in the triangle: " << ((bsp(a,b,c,Point(4,2))) ? "true" : "false") << std::endl;
    std::cout << "(7,4) is in the triangle: " << ((bsp(a,b,c,Point(7,4))) ? "true" : "false") << std::endl;
    std::cout << "(4,4) is in the triangle: " << ((bsp(a,b,c,Point(4,4))) ? "true" : "false") << std::endl;
    std::cout << "(4.5,3.3) is in the triangle: " << ((bsp(a,b,c,Point(4.5f,3.3f))) ? "true" : "false") << std::endl;
    std::cout << "(3.4,1) is in the triangle: " << ((bsp(a,b,c,Point(3.4f,1))) ? "true" : "false") << std::endl;

    

    return 0;
}
