#include "Point.hpp"

float get_sign(Point p1, Point p2, Point p3)
{
    return (((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())) - ((p2.getX() - p3.getX()) * (p1.getY() - p3.getY())));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    bool d1, d2, d3;

    d1 = get_sign(point, a, b) < 0;
    d2 = get_sign(point, b, c) < 0;
    d3 = get_sign(point, c, a) < 0;

    return (d1 == d2 && d2 == d3);
}