#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain   *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &src);

        void            makeSound()const;
        void            getIdeas()const;
        void            setIdea(size_t i, std::string idea);
};