#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    private:
        int _numberValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif // !FIXED_HPP
