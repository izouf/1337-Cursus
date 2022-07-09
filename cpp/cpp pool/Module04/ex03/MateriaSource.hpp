#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        int         amount;
        AMateria    *source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        virtual ~MateriaSource();
        MateriaSource   &operator=(const MateriaSource &src);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};