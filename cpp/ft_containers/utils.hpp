#pragma once

namespace   ft
{
    // Enable_if
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { typedef T	type; };

    //Is_integral

    template <typename T>
    struct is_integral { static bool const	value = false; };

    template <>
    struct is_integral<bool> { static bool const	value = true; };

    template <>
    struct is_integral<char> { static bool const    value = true; };

    template <>
    struct is_integral<char const> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned char> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned char const> { static bool const    value = true; };

    template <>
    struct is_integral<short> { static bool const    value = true; };

    template <>
    struct is_integral<short const> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned short> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned short const> { static bool const    value = true; };

    template <>
    struct is_integral<int> { static bool const    value = true; };

    template <>
    struct is_integral<int const> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned int> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned int const> { static bool const    value = true; };

    template <>
    struct is_integral<long> { static bool const    value = true; };

    template <>
    struct is_integral<long const> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned long> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned long const> { static bool const    value = true; };

    template <>
    struct is_integral<long long> { static bool const    value = true; };

    template <>
    struct is_integral<long long const> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned long long> { static bool const    value = true; };

    template <>
    struct is_integral<unsigned long long const> { static bool const    value = true; };

    // Lexicographical Compare Definition

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare
            (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2,
            typename ft::enable_if<!is_integral<InputIterator1>::value>::type* = NULL,
            typename ft::enable_if<!is_integral<InputIterator2>::value>::type* = NULL)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return (false);
            else if (*first1 < *first2)
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    //Equal Definition
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
            typename ft::enable_if<!is_integral<InputIterator1>::value>::type* = NULL,
            typename ft::enable_if<!is_integral<InputIterator2>::value>::type* = NULL)
    {
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return (false);
            ++first1;
            ++first2;
    }
    return (true);

    // Pair Definition

    template <class T1, class T2>
    struct pair
    {
        typedef T1	first_type;
        typedef T2	second_type;

        pair() : first(), second() {}
        template<class U, class V>
        pair(const pair<U, V> & pr) : first(pr.first), second(pr.second) {}
        pair(const first_type & a, const second_type & b) : first(a), second(b) {}
        virtual ~pair() {}
        pair &	operator=(const pair & pr) {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }

        T1	first;
        T2	second;
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs) {
        return !(lhs < rhs);
    }

    // Binary Function Definition
    template <class Arg1, class Arg2, class Result>
    struct binary_function {
        typedef Arg1	first_argument_type;
        typedef Arg2	second_argument_type;
        typedef Result	result_type;
    };

    //Less Definition

    template <class T>
    struct less : binary_function <T, T, bool> 
    {
        bool operator()(const T & x, const T & y) const
        {
            return (x < y);
        }
    };

    template <typename T>
    void	swap(T & a, T & b)
    {
        T	temp(a);

        a = b;
        b = temp;
    }
}