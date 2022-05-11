#include "phonebook.hpp"
#include <iostream>

void    menu()
{
    std::cout << "/******************************************/" << std::endl;
	std::cout << "/              PhoneBook                   /" << std::endl;
	std::cout << "/******************************************/" << std::endl;
	std::cout << "/      Choose the following commands       /" << std::endl;
	std::cout << "/                                          /" << std::endl;
	std::cout << "/      ADD                                 /" << std::endl;
	std::cout << "/      SEARCH                              /" << std::endl;
	std::cout << "/      EXIT                                /" << std::endl;
	std::cout << "/******************************************/" << std::endl;
}

int main()
{
	PhoneBook   phonebook;
	std::string command;

	menu();
	while (1)
	{
		std::cout << std::endl << "----->";
		std:: cin >> command;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
		{
			std::cout << "Closed" << std::endl;
			break;
		}
	}
	return (0);
}