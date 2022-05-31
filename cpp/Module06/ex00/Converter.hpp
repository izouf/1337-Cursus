#pragma once

#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <limits>
#include <cctype>


#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

class   Converter
{
    private:
        const std::string   _input;
        int                 _type;
        char                _char;
        int                 _int;
        float               _float;
        double              _double;         
    public:
        Converter();
        Converter(const std::string input);
        Converter(const Converter &copy);
        ~Converter();
        Converter &operator=(const Converter &src);

        std::string getInput() const;
        int         getType() const;
        char        getChar() const;
        int         getInt() const;
        float       getFloat() const;
        double      getDouble() const;

        int         checkInput();
        void        convertInput();

        void        printOutput() const;

        void    fromChar();
        void    fromInt();
        void    fromFloat();
        void    fromDouble();

        class   ErrorException : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Cannot be converted !");
                }
        };
};