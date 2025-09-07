#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b;
    Fixed c;
    Fixed d;

    a = Fixed(4.2f) * Fixed(2);
    b = Fixed(10) + Fixed(20);
    c = Fixed(5.5f) - Fixed(0.5f);
    d = Fixed(10.10f) / Fixed(2.2f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
