#include "RobotomyRequestForm.hpp"

const std::string &RobotomyRequestForm::name = std::string("Robotomy Request");

RobotomyRequestForm::RobotomyRequestForm() : target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form(RobotomyRequestForm::name, 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    this->target = src.target;
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    std::cout << "**** !@#$%^&*()_++_)(*&^%$#!@! ****" << std::endl;
    if ((rand() % 1))
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " Robotomization Failed !" << std::endl;
}