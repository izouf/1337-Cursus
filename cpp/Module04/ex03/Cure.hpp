#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &copy);
        virtual ~Cure();

        Cure &operator=(Cure const &other);

        AMateria* clone() const;
        void use(ICharacter& target);
};