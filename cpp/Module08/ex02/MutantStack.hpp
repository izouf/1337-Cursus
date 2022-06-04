#pragma once

#include <iostream>
#include <stack>
#include <algorithm>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename    MutantStack<T>::stack::container_type::iterator                 iterator;
        typedef typename    MutantStack<T>::stack::container_type::const_iterator           const_iterator;
        typedef typename    MutantStack<T>::stack::container_type::reverse_iterator         reverse_iterator;
        typedef typename    MutantStack<T>::stack::container_type::const_reverse_iterator   const_reverse_iterator;

        MutantStack();
        MutantStack(const MutantStack<T> &copy);
        ~MutantStack();
        MutantStack<T>   &operator=(const MutantStack<T> &src);

        iterator                    begin();
        iterator                    end();
        const_iterator              cbegin();
        const_iterator              cend();
        reverse_iterator            rbegin();
        reverse_iterator            rend();
        const_reverse_iterator      crbegin();
        const_reverse_iterator      crend();
        
};

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    *this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &src)
{
    if (*this != src)
        *this = src;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
    return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
    return this->c.crbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
    return this->c.crend();
}