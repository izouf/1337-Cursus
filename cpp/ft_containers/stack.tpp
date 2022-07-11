#pragma once

namespace ft
{
    template <class T, class Container>
    stack<T, Container>::stack(const Container &c) : _c(c) {}

    template <class T, class Container>
    stack<T, Container>::~stack() {}

    template <class T, class Container>
    bool stack<T, Container>::empty() const
    {
        return (_c.empty());
    }

    template <class T, class Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return (_c.size());
    }

    template <class T, class Container>
    typename stack<T, Container>::reference stack<T, Container>::top()
    {
        return (_c.back());
    }

    template <class T, class Container>
    typename stack<T, Container>::reference stack<T, Container>::top() const
    {
        return (_c.back());
    }

    template <class T, class Container>
    void stack<T, Container>::push(const value_type &x)
    {
        return (_c.push_back(x));
    }

    template <class T, class Container>
    void stack<T, Container>::pop()
    {
        return (_c.pop_back());
    }
}