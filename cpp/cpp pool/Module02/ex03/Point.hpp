#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const Fixed x, const Fixed y);
        Point(const Point &copy);

        ~Point();

        Point   &operator=(const Point &src);

        const Fixed &getX(void)const;
        const Fixed &getY(void)const;
};

std::ostream    &operator<<(std::ostream &o, Point const point);