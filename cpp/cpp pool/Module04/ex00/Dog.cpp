#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default Constructor Called !" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog Copy Constructor Called !" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void    Dog::makeSound()const
{
    std::cout << this->getType() << " : *** Wooof ! ***" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called !" << std::endl;
}