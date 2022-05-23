#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : amount(0)
{
    for (int i = 0; i < 4; i++)
        this->source[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : amount(0)
{
    *this = copy;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < this->amount; i++)
        delete (this->source[i]);
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &src)
{
    for (int i = 0; i < this->amount; i++)
        delete (this->source[i]);
    this->amount = 0;
    for (int i = 0; i < src.amount; i++)
        this->learnMateria(src.source[i]->clone());
    for (int i = 0; i < 4; i++)
        this->source[i] = nullptr;
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (this->amount == 4 || m == nullptr)
        return;
    for (int i = 0; i < this->amount; i++)
        if (this->source[i] == m)
            return;
    this->source[this->amount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->amount; i++)
        if(this->source[i]->getType() == type)
            return (this->source[i]->clone());
    return (nullptr);
}