#pragma once

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
    public:
        Intern();
        Intern(const Intern &copy);
        virtual ~Intern();
        Intern  &operator=(const Intern &src);

        class FormDoesNotExistException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("InternException: Form does not exist");
            }
        };

        Form    *makeForm(const std::string &form, const std::string &target) const;
};