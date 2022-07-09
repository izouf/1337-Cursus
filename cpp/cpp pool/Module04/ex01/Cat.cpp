#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor Called !" << std::endl;
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << "Cat Brain Allocation Failed !" << std::endl;
        exit(1);
    }
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
    std::cout << "Cat Copy Constructor Called !" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        this->type = src.type;
        *this->brain = *src.brain;
    }
    return (*this);
}

void    Cat::makeSound()const
{
    std::cout << this->getType() << " : *** Meeeeow ! ***" << std::endl;
}

void    Cat::getIdeas()const
{
    for (int i = 0; i < 100 ; i++)
    {
        std::cout << " Idea " << i << " of the Cat is : " << this->brain->getIdea(i) << std::endl;
    }
}

void    Cat::setIdea(size_t i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

Cat::~Cat()
{
    delete(this->brain);
    std::cout << "Cat Destructor Called !" << std::endl;
}