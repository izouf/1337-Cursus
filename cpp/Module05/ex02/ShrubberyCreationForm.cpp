#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>

const std::string &ShrubberyCreationForm::name = std::string("Shrubbery Creation");

std::string const ShrubberyCreationForm::tree[3] = {
	"      /\\\n" \
	"     /\\*\\\n" \
	"    /\\O\\*\\\n" \
	"   /*/\\/\\/\\\n" \
	"  /\\O\\/\\*\\/\\\n" \
	" /\\*\\/\\*\\/\\/\\\n" \
	"/\\O\\/\\/*/\\/O/\\\n" \
	"      ||\n" \
	"      ||\n" \
	"      ||\n",
	"         v\n" \
	"        >X<\n" \
	"         A\n" \
	"        d$b\n" \
	"      .d\\$$b.\n" \
	"    .d$i$$\\$$b.\n" \
	"       d$$@b\n" \
	"      d\\$$$ib\n" \
	"    .d$$$\\$$$b\n" \
	"  .d$$@$$$$\\$$ib.\n" \
	"      d$$i$$b\n" \
	"     d\\$$$$@$b\n" \
	"  .d$@$$\\$$$$$@b.\n" \
	".d$$$$i$$$\\$$$$$$b.\n" \
	"        ###\n" \
	"        ###\n" \
	"        ###\n",
	"         *\n" \
	"        /|\\\n" \
	"       /*|O\\\n" \
	"      /*/|\\*\\\n" \
	"     /X/O|*\\X\\\n" \
	"    /*/X/|\\X\\*\\\n" \
	"   /O/*/X|*\\O\\X\\\n" \
	"  /*/O/X/|\\X\\O\\*\\\n" \
	" /X/O/*/X|O\\X\\*\\O\\\n" \
	"/O/X/*/O/|\\X\\*\\O\\X\\\n" \
	"        |X|\n" \
	"        |X|\n"
};

ShrubberyCreationForm:: ShrubberyCreationForm() : target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target)
    : Form(ShrubberyCreationForm::name, 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    this->target = src.target;
    return (*this);
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    const std::string   shruName = (this->target + "_shrubbery");
    std::ofstream       outfile(shruName, std::ios::out);

    if (!outfile.is_open() || outfile.bad())
        throw (TargetFileOpenException());
    int c = (rand() % 6) + 1;
    for (int i = 0; i < c; i++)
    {
        outfile << ShrubberyCreationForm::tree[rand() % 3];
        if (outfile.bad())
        {
            outfile << std::endl;
            outfile.close();
            throw (WriteException());
        }
    }
    outfile << std::endl;
    outfile.close();
}