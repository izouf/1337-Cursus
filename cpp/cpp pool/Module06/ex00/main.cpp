#include "Converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong Args !" << std::endl;
        return (1);
    }
    try
    {
        Converter converter(av[1]);
    }
    catch(const Converter::ErrorException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}