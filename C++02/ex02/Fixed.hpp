#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _numberValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;
        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b) ; 
        static const Fixed& min(const Fixed& a, const Fixed& b); 
        static Fixed& max(Fixed& a, Fixed& b); 
        static const Fixed& max(const Fixed& a, const Fixed& b); 
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); 

#endif // !FIXED_HPP
