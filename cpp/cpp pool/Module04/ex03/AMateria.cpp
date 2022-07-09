#include "AMateria.hpp"

AMateria::AMateria() : type("Uknown")
{
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (this->type);
}

AMateria::~AMateria()
{
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}