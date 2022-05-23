#include "Animal.hpp"

Animal::Animal() : type("Uknown")
{
    std::cout << "Animal Default Constructor Called !" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal Copy Constructor Called !" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void    Animal::makeSound()const
{
    std::cout << "Uknown Animal ! Uknown Sound !" << std::endl;
}

std::string Animal::getType()const
{
    return (this->type);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called !" << std::endl;
}