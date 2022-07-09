#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
typedef struct Data
{
    std::string name;
    size_t      n;
    Data        *next;
}               Data;

class Serializer
{
    private:
    public:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();
        Serializer &operator=(const Serializer &src);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};