#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:
    std::string                 target;
    static const std::string    tree[3];
    public:
        static const std::string    &name;

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        class TargetFileOpenException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("ShrubberyCreationFormException: Cannot open file");
            }
        };

        class WriteException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("ShrubberyCreationFormException: Error while writing to the file");
            }
        };

        void execute(const Bureaucrat &executor) const;
};