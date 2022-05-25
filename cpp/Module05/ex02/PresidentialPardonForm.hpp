#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
    std::string           target;
    public:
        static const std::string    &name;

        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        void execute(const Bureaucrat &executor) const;
};