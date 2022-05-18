#pragma once

#include <iostream>

class   Fixed
{
    private:
        int                 fp;
        static const int    frac;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
