#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Lhaj("Lhaj", 100);
	std::cout <<  Lhaj << std::endl;
	try
	{
		Form	f1("Taxe1", 100 , 50);
		std::cout << f1 << std::endl;
		f1.beSigned(Lhaj);
		std::cout << f1 << std::endl;
		f1.beSigned(Lhaj);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-----------------" << std::endl;

	Form	f2("Taxe2", 99, 50);
	std::cout << f2 << std::endl;

    try
	{
		Lhaj.signForm(f2);
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}