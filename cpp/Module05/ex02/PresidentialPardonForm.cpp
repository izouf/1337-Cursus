#include "PresidentialPardonForm.hpp"

const std::string &PresidentialPardonForm::name = std::string("Presidential Pardon");

PresidentialPardonForm::PresidentialPardonForm() : target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(PresidentialPardonForm::name, 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    this->target = src.target;
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}