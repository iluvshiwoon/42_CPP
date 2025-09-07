#include "Fixed.hpp"
#include <ostream>
#include <cmath>

Fixed::Fixed() :
    _numberValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value) : 
    _numberValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int value) :
    _numberValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
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

float Fixed::toFloat() const {
    return static_cast<float>(_numberValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _numberValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

bool Fixed::operator>(const Fixed& rhs) {
    return _numberValue > rhs._numberValue;
}

bool Fixed::operator<(const Fixed& rhs) {
    return _numberValue < rhs._numberValue;
}

bool Fixed::operator>=(const Fixed& rhs) {
    return _numberValue >= rhs._numberValue;
}

bool Fixed::operator<=(const Fixed& rhs) {
    return _numberValue <= rhs._numberValue;
}

bool Fixed::operator==(const Fixed& rhs) {
    return _numberValue == rhs._numberValue;
}

bool Fixed::operator!=(const Fixed& rhs) {
    return _numberValue != rhs._numberValue;
}

Fixed Fixed::operator+(const Fixed& rhs) {
    Fixed rvalue;

    rvalue.setRawBits(_numberValue + rhs._numberValue);
    return rvalue;
}

Fixed Fixed::operator-(const Fixed& rhs) {
    Fixed rvalue;

    rvalue.setRawBits(_numberValue - rhs._numberValue);
    return rvalue;
}

Fixed Fixed::operator*(const Fixed& rhs) {
    Fixed rvalue;

    rvalue.setRawBits((_numberValue * rhs._numberValue)>>_fractionalBits);
    return rvalue;
}

Fixed Fixed::operator/(const Fixed& rhs) {
    Fixed rvalue;

    rvalue.setRawBits((_numberValue << _fractionalBits) / rhs._numberValue);
    return rvalue;
}
