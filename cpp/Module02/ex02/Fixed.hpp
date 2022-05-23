#pragma once

#include <string>
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

        bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;

        float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;

        Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);

        float toFloat( void ) const;
        int toInt( void ) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(Fixed const &a, Fixed const &b);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);