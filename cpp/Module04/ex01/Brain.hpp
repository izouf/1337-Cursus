#pragma once

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &src);
        virtual ~Brain();

        const std::string   getIdea(size_t i) const;
        void                setIdea(size_t i, std::string idea);
};