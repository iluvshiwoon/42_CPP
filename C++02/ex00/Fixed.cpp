#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() :
    _numberValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) :
    _numberValue(other._numberValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        _numberValue = rhs._numberValue; 
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _numberValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _numberValue = raw;
}

