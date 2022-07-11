#pragma once

namespace ft
{
    // enable_if
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {typedef T type;};

    //is_integral

    template <typename T>
    struct is_integral { static bool const value = false;};

    template <>
    struct is_integral<bool> {static bool const value = true;};

    template <>
    struct is_integral<char> {static bool const value = true;};

    template <>
    struct is_integral<const char> {static bool const value = true;};

    template <>
    struct is_integral<unsigned char> {static bool const value = true;};

    template <>
    struct is_integral<unsigned const char> {static bool const value = true;};

    template <>
    struct is_integral<short> {static bool const value = true;};

    template <>
    struct is_integral<const short> {static bool const value = true;};

    template <>
    struct is_integral<unsigned const short> {static bool const value = true;};

    template <>
    struct is_integral<int> {static bool const value = true;};

    template <>
    struct is_integral<const int> {static bool const value = true;};

    template <>
    struct is_integral<unsigned int> {static bool const value = true;};

    template <>
    struct is_integral<unsigned const int> {static bool const value = true;};

    template <>
    struct is_integral<long> {static bool const value = true;};

    template <>
    struct is_integral<unsigned long> {static bool const value = true;};

    template <>
    struct is_integral<const long> {static bool const value = true;};

    template <>
    struct is_integral<unsigned const long> {static bool const value = true;};

    template <>
    struct is_integral<long long> {static bool const value = true;};

    template <>
    struct is_integral<const long long> {static bool const value = true;};

    template <>
    struct is_integral<unsigned long long> {static bool const value = true;};

    template <>
    struct is_integral<unsigned constlong long> {static bool const value = true;};
}