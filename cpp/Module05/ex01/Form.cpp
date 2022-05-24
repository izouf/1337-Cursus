#include "Form.hpp"

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw (Form::GradeTooHighException());
    else if (signGrade > 150 || executeGrade > 150)
        throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy): name(copy.name), sign(false), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{ 
    *this = copy;
}

Form::~Form()
{
}

Form    &Form::operator=(const Form &copy)
{
    this->sign = copy.sign;
    return (*this);
}

const std::string &Form::getName()const
{
    return (this->name);
}

bool    Form::isSigned()const
{
    return (this->sign);
}

int     Form::getSignGrade()const
{
    return (this->signGrade);
}

int     Form::getExecuteGrade()const
{
    return (this->executeGrade);
}

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw (Form::GradeTooLowException());
    else if (this->sign)
        throw Form::FormAlreadySignedException();
    this->sign = true;
}

std::ostream &operator<<(std::ostream &out , const Form &form)
{
    out << form.getName() << ((form.isSigned()) ? " \"Signed\" " : " \"Unsigned\" ")
        << "Sign :" << form.getSignGrade() << ", Execute: " << form.getExecuteGrade() ;
        return (out);
}