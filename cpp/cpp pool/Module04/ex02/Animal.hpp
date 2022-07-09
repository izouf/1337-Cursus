#pragma once

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &src);
        virtual ~Animal();

        std::string     getType()const;
        virtual void    makeSound()const = 0;
};