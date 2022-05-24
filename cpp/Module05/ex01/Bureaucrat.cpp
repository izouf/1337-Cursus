#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) , grade(grade)
{
    if (this->grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (this->grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{    
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &src)
{
    this->grade = src.grade;
    return (*this);
}

Bureaucrat::Bureaucrat()
{ 
}

const std::string   &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw (Bureaucrat::GradeTooHighException());
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw (Bureaucrat::GradeTooLowException());
    this->grade++;
}

void    Bureaucrat::signForm(Form &form)const
{
    if (form.isSigned())
    {
        std::cout << *this << " couldn't sign " << form << " because the form is already signed." << std::endl;
    }
    else if (form.getSignGrade() < this->grade)
    {
        std::cout << *this << " couldn't sign " << form << " because it's grade is too low." << std::endl; 
    }
    else
        std::cout << *this << " signs " << form << std::endl;
    form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() <<  ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
