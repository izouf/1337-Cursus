#pragma once

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T>>
    class stack
    {
        public:
            typedef typename Container::value_type          value_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;
            typedef typename Container::size_type           size_type;
            typedef Container                               container_type;
        protected:
            Container _c;
        public:
            explicit stack(const Container &c = Container());

            ~stack();

            bool empty()const;

            size_type size() const;

            reference top();

            const_reference top() const;

            void push(const value_type &x);

            void pop();

            template <typename Type, typename Ctnr>
            friend bool operator==(const stack<Type, Ctnr> &, const stack<Type, Ctnr> &);

            template <typename Type, typename Ctnr>
            friend bool operator<(const stack<Type, Ctnr> &, const stack<Type, Ctnr> &);
    };

    template <typename T, typename Container>
    inline bool operator==(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (x._c == y._c);
    }

    template <typename T, typename Container>
    inline bool operator!=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (!(x == y));
    }

    template <typename T, typename Container>
    inline bool operator<(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (x._c < y._c);
    }

    template <typename T, typename Container>
    inline bool operator<=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (!(y < x));
    }

    template <typename T, typename Container>
    inline bool operator>(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (y < x);
    }

    template <typename T, typename Container>
    inline bool operator>=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return (!(x < y));
    }
}
#include "stack.tpp"