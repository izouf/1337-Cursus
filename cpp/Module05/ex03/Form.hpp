#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;
class   Form
{
    private:
        const std::string   name;
        bool                sign;
        const int           signGrade;
        const int           executeGrade;
    public:
        Form();
        Form(const std::string &name, const int signGrade, const int executeGrade);
        Form(const Form &copy);
        virtual ~Form();

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

        class   FormAlreadySignedException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("FormException: The Form is already signed");
            }
        };

        class   UnsignedFormException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("FormException: Unsigned form can not be executed");
            }
        };

        Form   &operator=(const Form &src);

        const std::string   &getName()const;
        virtual bool        isSigned()const;
        int                 getSignGrade()const;
        int                 getExecuteGrade()const;

        void                beSigned(const Bureaucrat &bureaucrat); 
        virtual void        execute(Bureaucrat const &bureaucrat)const = 0;
};

std::ostream &operator<<(std::ostream &out, Form const &form);