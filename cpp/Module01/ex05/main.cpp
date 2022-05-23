#include "Harl.hpp"

int main()
{
    Harl    harl;

    std::cout << "Hall complains " << std::endl << "******************";
    std::cout << std::endl;
    harl.complain("DEBUG"); 
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << "******************"  << std::endl;
    std::cout << "Thank you " << std::endl;;
    return (0);
}