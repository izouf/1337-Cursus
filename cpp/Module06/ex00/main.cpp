#include "Converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong Args !" << std::endl;
        return (1);
    }

    double      value;
    Converter   converter;

    try
    {
        value = std::stod(av[1]);
    }
    catch (std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
        return (1);
    }

    try
    {
        char    c = converter.toChar(value);
        std::cout << "char : '" << c << "'" << std::endl;
    }
    catch(std::string &e)
    {
        std::cout << "char : " << e << std::endl;
    }

    try
    {
        std:: cout << "int : " << converter.toInt(value) << std::endl;
    }
    catch(const std::string &e)
    {
        std::cout << e << std::endl;
    }

    float   f = converter.toFloat(value);
    if (f - static_cast<int>(f) != 0)
        std::cout << "float : " << f << "f" << std::endl;
    else
        std::cout << "float : " << f << ".0f" << std::endl;

    double  d = converter.toDouble(value);
    if (d - static_cast<int>(d) != 0)
        std::cout << "double : " << d << std::endl;
    else
        std::cout << "double :" << d <<  ".0" << std::endl;

    return (0);
}