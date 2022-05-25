#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern  &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}

Form    *Intern::makeForm(const std::string &form, const std::string &target) const
{
      Form *F[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
    };
    std::string choice[3] = {
        "shrubbery request",
        "robotomy request",
        "presidential request",
    };
    for (int i = 0; i < 3; i++)
    {
        if (form == choice[i])
        {
            for (int j = 0 ; j < 3; j++)
                if (j != i)
                    delete F[j];
                std::cout  << "Intern creates " << form << std::endl;
            return F[i];
        }
    }
    for (int j = 0 ; j < 3; j++)
        delete F[j];
    throw (FormDoesNotExistException());
    return (0);
}


