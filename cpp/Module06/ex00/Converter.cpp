#include "Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(const Converter &copy)
{
    *this = copy;
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

char    Converter::toChar(double v)
{
    char    value = static_cast<char>(v);
    if (std::isinf(v) || std::isnan(v))
        throw (std::string("cannot be measured"));
    else if (value < 32 || value > 126)
        throw (std::string ("Non printable"));
    return (value);
}

int    Converter::toInt(double v)
{
    int     value = static_cast<int>(v);
    if (std::isinf(v) || std::isnan(v) || v > INT_MAX || v < INT_MIN)
        throw (std::string("cannot be measured"));
    return (value);
}

float   Converter::toFloat(double v)
{
    return (static_cast<float>(v));
}

double  Converter::toDouble(double v)
{
    return (static_cast<double>(v));
}