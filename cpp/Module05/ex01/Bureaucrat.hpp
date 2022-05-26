#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
class Form;
class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        virtual ~Bureaucrat();

        class   GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw()
            {
                 return ("BureaucratException : Grade too High");
            }
        };
        class   GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("BureaucratException : Grade too Low");
            }
        };

        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string   &getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();
        void                signForm(Form &form)const;
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);