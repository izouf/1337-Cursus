#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default Constructor Called !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "WrongCat Copy Constructor Called !" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void    WrongCat::makeSound()const
{
    std::cout << this->getType() << "  : *** WrongCat Sound ! ***" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called !" << std::endl;
}