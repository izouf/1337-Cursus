#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
    (void)copy;
}

Ice &Ice::operator=(const Ice &src)
{
    (void)src;
    return (*this);
}

AMateria *Ice::clone(void) const
{
    AMateria *copy = new Ice(*this);
    return (copy);
}

void    Ice::use(ICharacter &target)
{
    std::cout  << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
} 

Ice::~Ice()
{
}