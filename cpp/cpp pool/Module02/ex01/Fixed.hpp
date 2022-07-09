#pragma once

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
        int                 fp;
        static const int    frac;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &src);

        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);