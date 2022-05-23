#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &src);

        void            makeSound()const;
        void            getIdeas()const;
        void            setIdea(size_t i, std::string idea);
};