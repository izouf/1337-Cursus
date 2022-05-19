#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main( void ) 
{
    {
        Point P(Fixed(6), Fixed(7));
        Point a;
        Point b(Fixed(10), Fixed(10));
        Point c(Fixed(20), Fixed(0));

        std::cout << (bsp(a, b, c, P) ? "P is inside abc" : "P is outside abc") << std::endl;
    }
    {
        Point P(Fixed(6), Fixed(5));
        Point a;
        Point b(Fixed(10), Fixed(10));
        Point c(Fixed(20), Fixed(0));

        std::cout << (bsp(a, b, c, P) ? "P is inside abc" : "P is outside abc") << std::endl;
    }
    return 0;
}