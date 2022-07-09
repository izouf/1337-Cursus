#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Lhaj("Lhaj", 100);
	std::cout << Lhaj << std::endl;
	Lhaj.incrementGrade();
	std::cout << Lhaj << std::endl;
	Lhaj.decrementGrade();
	std::cout << Lhaj << std::endl;

	try
	{
		Bureaucrat Houssam("Houssam", 0);
		std::cout << Houssam << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Houssam("Houssam", 151);
		std::cout << Houssam << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Houssam("Houssam", 1);
		std::cout << Houssam << std::endl;
		Houssam.incrementGrade();
		std::cout << Houssam << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Houssam("Houssam", 150);
		std::cout << Houssam << std::endl;
		Houssam.decrementGrade();
		std::cout << Houssam << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
