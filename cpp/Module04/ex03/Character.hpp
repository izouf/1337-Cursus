#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        int         equiped;
        int         unequiped;
        AMateria    *inventory[4];
        AMateria    *floor[100];
    public:
        Character();
        Character(std::string const &name);
        Character(const Character &copy);
        Character &operator=(const Character &src);
        ~Character();

        std::string const &getName(void) const;

        void equip(AMateria* m);
        void unequip(int index);
        void use(int index, ICharacter& target);
};