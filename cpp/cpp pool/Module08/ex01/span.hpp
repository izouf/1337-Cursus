#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>

class Span
{
    private:
        std::vector<int>    storage;
        unsigned int        size;
        unsigned int        pos;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &src);

        void            addNumber(int number);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
        void            addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);

        unsigned int    getSize() const;

        class InvalidVectorException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Invalid Vector !");
                }
        };

        class FullArrayException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Full Array !");
                }
        };

         class InvalidComparisonException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Invalid Comparison !");
                }
        };
};