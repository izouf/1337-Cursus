#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
	srand(time(NULL));

	Bureaucrat Lhaj("Lhaj",1);
	std::cout <<  Lhaj << std::endl;
	Bureaucrat	Houssam("Houssam", 25);
	std::cout <<  Houssam << std::endl;

	Form	*shrub = new ShrubberyCreationForm("home");
	std::cout <<  *shrub << std::endl;
	shrub->beSigned(Lhaj);
	shrub->execute(Houssam);

	Form	*cyborg = new RobotomyRequestForm("Cyborg");
	std::cout <<  *cyborg << std::endl;
	cyborg->beSigned(Houssam);
	cyborg->execute(Lhaj);
	Houssam.executeForm(*cyborg);
	Houssam.executeForm(*cyborg);

	Form	*pardon = new PresidentialPardonForm("Houssam");
	std::cout << *pardon << std::endl;
	Lhaj.signForm(*pardon);
	pardon->execute(Lhaj);

	std::cout << "-----------------" << std::endl;
	try
	{
		Houssam.executeForm(*pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "-----------------" << std::endl;

	try
	{
		RobotomyRequestForm cyborg = RobotomyRequestForm("Cyborg");
		std::cout << cyborg << std::endl;
		cyborg.execute(Lhaj);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;

	try
	{
		PresidentialPardonForm pardon = PresidentialPardonForm("Houssam");
		std::cout << pardon << std::endl;
		Houssam.signForm(pardon);
		pardon.execute(Lhaj);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;

	try
	{
		PresidentialPardonForm pardon = PresidentialPardonForm("Houssam");
		std::cout << pardon << std::endl;
		Lhaj.signForm(pardon);
		Houssam.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	{
		Intern *i = new Intern();
		Form	*f, *f2;

		f = i->makeForm("presidential request", "Houssam");
		

		Lhaj.signForm(*f);
		Lhaj.executeForm(*f);

		try
		{
			f2 = i->makeForm("denya", "Houssam");
			f2->beSigned(Houssam);
			Houssam.executeForm(*f2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		delete (i);
	}
	delete (shrub);
	delete (cyborg);
	delete (pardon);
	
    return (0);
}