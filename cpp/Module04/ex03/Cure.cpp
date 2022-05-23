#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
    (void)copy;
}

Cure &Cure::operator=(const Cure &src)
{
    (void)src;
    return (*this);
}

AMateria *Cure::clone(void) const
{
    AMateria *copy = new Cure(*this);
    return (copy);
}

void    Cure::use(ICharacter &target)
{
    std::cout  << "* Heals " << target.getName() << "'s wounds *" << std::endl;
} 

Cure::~Cure()
{
}