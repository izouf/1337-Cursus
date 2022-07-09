#include "easyfind.hpp"
#include <list>

int main()
{
    std::list<int> test;

    test.push_back(120);
    test.push_back(121);
    test.push_back(122);

    std::list<int>::const_iterator it;

    try
    {
        it = ::easyfind(test, 121);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (it != test.end())
        std::cout << *it << " found" << std::endl;
    it = test.end();
    try
    {
        it = ::easyfind(test, 5);
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (it != test.end())
        std::cout << *it << "found" << std::endl;
    return (0);
}