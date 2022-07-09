#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called !" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    *this = copy;
    std::cout << "Brain Copy Constructor Called !" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
        {
            if (src.ideas[i].length() > 0)
                this->ideas[i] = src.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called !" << std::endl;
}

const std::string   Brain::getIdea(size_t i) const
{
    if (i < 100)
        return (this->ideas[i]);
    return ("There is only 100 ideas per brain T_T !");
}

void    Brain::setIdea(size_t i, std::string idea)
{
    if (i < 100)
        this->ideas[i] = idea;
    else
        std::cout << "There is only 100 ideas per brain T_T !" << std::endl;
}