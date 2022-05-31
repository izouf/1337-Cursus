#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array
{
    private:
        T               *array;
        unsigned int    size;
    public:
        Array(){array = nullptr; size = 0;};
        Array(unsigned int size) : array(new T[size]), size(size){};
        Array(const Array &copy) { *this = copy;};
        ~Array(){delete[] array;};

        unsigned int  getSize(void) const{ return (this->size);}

        Array   &operator=(const Array &src)
        {
            if (this != &src)
            {
                if (size != src.size)
                {
                    delete[] array;
                    size = src.size;
                    array = new T[size];
                }
                for (unsigned int i = 0; i < src.size; i++)
                    array[i] = src.array[i];
            }
            return (*this);
        }

        T&  operator[](unsigned int n)
        {
            if (n < 0 || n >= size)
                throw (Array::OutOfBoundsIndexException());
            return array[n];
        }

        class OutOfBoundsIndexException : public std::exception
        {
            public:
                char const *what() const throw ()
                {
                    return ("Out of bound !");
                }
        };
};