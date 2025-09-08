#include "Fixed.hpp"
#include <ostream>
#include <cmath>

Fixed::Fixed() :
    _numberValue(0) {
}

Fixed::Fixed(const float value) : 
    _numberValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
}

Fixed::Fixed(const int value) :
    _numberValue(value << _fractionalBits) {
}

Fixed::Fixed(const Fixed& other) :
    _numberValue(other._numberValue) {
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        _numberValue = rhs._numberValue; 
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return _numberValue;
}

void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator>(const Fixed& rhs) const {
    return _numberValue > rhs._numberValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return _numberValue < rhs._numberValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return _numberValue >= rhs._numberValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return _numberValue <= rhs._numberValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return _numberValue == rhs._numberValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return _numberValue != rhs._numberValue;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed rvalue;

    rvalue.setRawBits(_numberValue + rhs._numberValue);
    return rvalue;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed rvalue;

    rvalue.setRawBits(_numberValue - rhs._numberValue);
    return rvalue;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed rvalue;

    rvalue.setRawBits((_numberValue * rhs._numberValue)>>_fractionalBits);
    return rvalue;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed rvalue;

    rvalue.setRawBits((_numberValue << _fractionalBits) / rhs._numberValue);
    return rvalue;
}

Fixed& Fixed::operator++() {
    _numberValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _numberValue += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    _numberValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _numberValue -= 1;
    return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
