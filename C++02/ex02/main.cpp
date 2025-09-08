#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "5.5 > 2.1 : " << ((Fixed(5.5f) > Fixed(2.1f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 < 2.1 : " << ((Fixed(5.5f) < Fixed(2.1f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 >= 2.1 : " << ((Fixed(5.5f) >= Fixed(2.1f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 <= 2.1 : " << ((Fixed(5.5f) <= Fixed(2.1f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 >= 5.5 : " << ((Fixed(5.5f) >= Fixed(5.5f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 <= 5.5 : " << ((Fixed(5.5f) <= Fixed(5.5f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 == 5.5 : " << ((Fixed(5.5f) == Fixed(5.5f)) ? "true" : "false") << std::endl;
    std::cout << "5.5 != 5.5 : " << ((Fixed(5.5f) != Fixed(5.5f)) ? "true" : "false") << std::endl;

    std::cout << "5.5 + 5.5 : " << Fixed(5.5f) + Fixed(5.5f) << std::endl;
    std::cout << "5.5 - 5.5 : " << Fixed(5.5f) - Fixed(5.5f) << std::endl;
    std::cout << "5.5 * 5.5 : " << Fixed(5.5f) * Fixed(5.5f) << std::endl;
    std::cout << "5.5 / 5.5 : " << Fixed(5.5f) / Fixed(5.5f) << std::endl;

    std::cout << "++5.5 : " << ++Fixed(5.5f) << std::endl;
    std::cout << "5.5++ : " << Fixed(5.5f)++ << std::endl;
    std::cout << "--5.5 : " << --Fixed(5.5f) << std::endl;
    std::cout << "5.5-- : " << Fixed(5.5f)-- << std::endl;

    std::cout << "max(5.5, 2.1) : " << Fixed::max(Fixed(5.5f), Fixed(2.1f)) << std::endl;
    std::cout << "min(5.5, 2.1) : " << Fixed::min(Fixed(5.5f), Fixed(2.1f)) << std::endl;
    return 0;
}
