#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
    std::string           target;
    public:
        static const std::string    &name;

        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        void    execute(const Bureaucrat &executor) const;
};