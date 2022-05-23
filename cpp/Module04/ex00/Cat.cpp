#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor Called !" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
    std::cout << "Cat Copy Constructor Called !" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void    Cat::makeSound()const
{
    std::cout << this->getType() << " : *** Meeeeow ! ***" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called !" << std::endl;
}