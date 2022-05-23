#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &src);
        ~WrongAnimal();

        std::string     getType()const;
        void            makeSound()const;
};