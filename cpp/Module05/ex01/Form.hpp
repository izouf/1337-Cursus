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
        ~Form();

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
                return ("BureaucratException : Grade too High");
            }
        };
        class   FormAlreadySignedException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("FormException: The Form is already signed");
            }
        };
        Form   &operator=(const Form &src);

        const std::string   &getName()const;
        bool                isSigned()const;
        int                 getSignGrade()const;
        int                 getExecuteGrade()const;

        void                beSigned(const Bureaucrat &bureaucrat); 
};

std::ostream &operator<<(std::ostream &out, Form const &form);