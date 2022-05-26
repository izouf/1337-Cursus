#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <limits>

class   Converter
{
    public:
        Converter();
        Converter(const Converter &copy);
        ~Converter();
        Converter &operator=(const Converter &src);

        char    toChar(double v);
        int     toInt(double v);
        float   toFloat(double v);
        double  toDouble(double v);

        class   ConvertException : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Cannot be converted !");
                }
        };
};