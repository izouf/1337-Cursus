#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
    int i;
    void    (Harl::*functionPTRS[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (i = 0; i < 4; i++)
	{
		if (str[i] == level)
			break;
	}
    switch(i)
    {
        case(0):
            (this->*functionPTRS[0])();
        case(1):
            (this->*functionPTRS[1])();
        case(2):
            (this->*functionPTRS[2])();
        case(3):
            (this->*functionPTRS[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}