#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : 
    _x(0), _y(0) {
}

Point::Point(const float x, const float y) :
    _x(x), _y(y) {
}

Point::Point(const Point& other) :
    _x(other._x), _y(other._y) {
}

Point& Point::operator=(const Point& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

Point::~Point() {};

Fixed Point::x() const {
    return _x;
}

Fixed Point::y() const {
    return _y;
}
