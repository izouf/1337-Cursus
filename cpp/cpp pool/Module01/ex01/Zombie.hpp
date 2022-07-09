#pragma once

#include <iostream>
#include <string>

class   Zombie
{
private:
    std::string name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    setName(const std::string str);
    void    announce(void);
};

Zombie* zombieHorde(int N, std::string name);
Zombie  *newZombie(std::string name);
void    randomChump(std::string name);