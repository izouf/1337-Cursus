#pragma once

#include <iostream>
#include <string>

class   Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);