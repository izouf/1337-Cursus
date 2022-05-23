#pragma once
#include <iostream>

class   Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(const std::string &weapon);
    ~Weapon();
    std::string getType() const;
    void        setType(const std::string &weapon);
};