#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const Fixed x, const Fixed y): x(x) , y(y){}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY()){}

Point::~Point(){}

Point   &Point::operator=(const Point &src)
{
    if (this != &src)
    {
        const_cast<Fixed&>(this->x) =src.x;
        const_cast<Fixed&>(this->y) = src.y;
    }
    return (*this);
}

const Fixed &Point::getX(void)const
{
    return (this->x);
}

const Fixed &Point::getY(void)const
{
    return (this->y);
}

std::ostream    &operator<<(std::ostream &o, Point const point)
{
    o << "x: " << point.getX() << " / y: " << point.getY() << std::endl;
    return (o);
}