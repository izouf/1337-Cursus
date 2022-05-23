#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Uknown")
{
    std::cout << "WrongAnimal Default Constructor Called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "WrongAnimal Copy Constructor Called !" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void    WrongAnimal::makeSound()const
{
    std::cout << this->getType() << " : *** WrongAnimal Sound ! ***" << std::endl;
}

std::string WrongAnimal::getType()const
{
    return (this->type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called !" << std::endl;
}