#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default Constructor Called !" << std::endl;
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << "Dog Brain Allocation Failed !" << std::endl;
        exit(1);
    }
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog Copy Constructor Called !" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
    {
        delete (this->brain);
        this->type = src.type;
        this->brain = new Brain();
        if (this->brain == NULL)
        {
            std::cout << "Dog Brain Allocation Failed !" << std::endl;
            exit(1);
        }
    }
    *this->brain = *src.brain;
    return (*this);
}

void    Dog::makeSound()const
{
    std::cout << this->getType() << " : *** Wooof ! ***" << std::endl;
}

void    Dog::getIdeas()const
{
    for (int i = 0; i < 100 ; i++)
    {
        std::cout << " Idea " << i << " of the Dog is : " << this->brain->getIdea(i) << std::endl;
    }
}

void    Dog::setIdea(size_t i, std::string idea)
{
    this->brain->setIdea(i, idea);
}

Dog::~Dog()
{
    delete(this->brain);
    std::cout << "Dog Destructor Called !" << std::endl;
}