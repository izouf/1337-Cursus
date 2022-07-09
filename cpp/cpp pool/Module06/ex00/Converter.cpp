#include "Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(const std::string input) : _input(input)
{
    this->_double = atof(this->getInput().c_str());
    this->convertInput();
    this->printOutput();
}

Converter::Converter(const Converter &copy) : _input(copy.getInput())
{
    *this = copy;
    this->printOutput();
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &src)
{
    if (this == &src)
        return (*this);
    this->_type = src.getType();
    this->_char = src.getChar();
    this->_int  = src.getInt();
    this->_float = src.getFloat();
    this->_double = src.getDouble();
    return (*this);
}

std::string Converter::getInput()const
{
    return (this->_input);
}

int Converter::getType()const
{
    return (this->_type);
}

char Converter::getChar()const
{
    return (this->_char);
}
int Converter::getInt()const
{
    return (this->_int);
}
float Converter::getFloat()const
{
    return (this->_float);
}
double Converter::getDouble()const
{
    return (this->_double);
}

int Converter::checkInput()
{
    if (this->getInput().compare("nan") == 0 || this->getInput().compare("nanf") == 0 || this->getInput().compare("+inf") == 0
        || this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0
        || this->getInput().compare("-inff") == 0)
    {
        return (NAN_INF);
    }
    else if (this->getInput().length() == 1
        && (this->getInput()[0] == '+' || this->getInput()[0] == '-'
        || this->getInput()[0] == 'f' || this->getInput()[0] == '.')) // avoid interpreting single int as char
    {
        return (CHAR);
    }
    else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-")) // handle multiple -+
        return (ERROR);
    else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
        return (INT);
    else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
    {
        if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") // 0..0 case
            || isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false // 0. case
            || this->getInput().find_first_of(".") == 0) // .0 case
        {
            return (ERROR);
        }
        else
            return (DOUBLE);
    }
    else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
    {
        if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") // 0.0ff case
            || this->getInput().find_first_of(".") != this->getInput().find_last_of(".") // 0..0f case
            || this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 // 0.f case
            || this->getInput().find_first_of(".") == 0 // .0f case
            || this->getInput()[this->getInput().find_first_of("f") + 1] != '\0') // 0.0f0
        {
            return (ERROR);
        }
        else
            return (FLOAT);
    }
    else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0]))
        || (this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
    {
        return (CHAR);
    }
    else
        return (ERROR);
}

void    Converter::fromChar()
{
    this->_char = static_cast<unsigned char>(this->getInput()[0]);
    this->_int = static_cast<int>(this->getChar());
    this->_float = static_cast<float>(this->getChar());
    this->_double = static_cast<double>(this->getChar());
}

void    Converter::fromInt()
{
    this->_int = static_cast<int>(this->getDouble());
    this->_char = static_cast<unsigned char>(this->getInt());
    this->_float = static_cast<float>(this->getDouble());
}

void    Converter::fromFloat()
{
    this->_float = static_cast<float>(this->getDouble());
    this->_char = static_cast<char>(this->getFloat());
    this->_int = static_cast<int>(this->getFloat());
}

void    Converter::fromDouble()
{
    this->_char = static_cast<char>(this->getDouble());
    this->_int = static_cast<int>(this->getDouble());
    this->_float = static_cast<float>(this->getDouble());
}

void    Converter::convertInput()
{
    int i;

    void (Converter::*fptr[])(void) = {&Converter::fromChar, &Converter::fromInt, &Converter::fromFloat, &Converter::fromDouble};
    int types[] = {CHAR, INT, FLOAT, DOUBLE};

    this->_type = checkInput();
    if (this->getType() == NAN_INF)
        return ;
    for (i = 0; i < 4; i++)
    {
        if (this->getType() == types[i])
        {
            (this->*fptr[i])();
            break;
        }
    }
    if (i == 4)
        throw (Converter::ErrorException());
}

void    Converter::printOutput()const
{
    // Char
    if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
    {
        if (isprint(this->getChar()))
            std::cout << "char : '" << this->getChar() << "'" << std::endl;
        else
            std::cout << "char : Non Printable" << std::endl;
    }
    else
        std::cout << "char : impossible" << std::endl;
    // Int
    if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min()
        && this->getDouble() <= std::numeric_limits<int>::max())
            std::cout << "int : " << this->getInt() << std::endl;
    else
        std::cout << "int : impossible" << std::endl;
    // Float
    if (this->getType() != NAN_INF)
    {
        std::cout << "float : " << this->getFloat();
        if (this->getFloat() - this->getInt() == 0)
            std::cout << ".0f" <<std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
    {
        if (this->getInput() == "nan" || this->getInput() == "nanf")
            std::cout << "float : nanf" << std::endl;
        else if (this->getInput()[0] == '+')
            std::cout << "float : +inff" << std::endl;
        else
            std::cout << "float : -inff" << std::endl;
    }
    // Double
    if (this->getType() != NAN_INF)
    {
        std::cout << "double : " << this->getDouble();
        if (this->getDouble() - this->getInt() == 0)
                std::cout << ".0" <<std::endl;
        else
            std::cout << std::endl;
    }
    else
    {
        if (this->getInput() == "nan" || this->getInput() == "nanf")
            std::cout << "double : nan" << std::endl;
        else if (this->getInput()[0] == '+')
            std::cout << "double : +inf" << std::endl;
        else
            std::cout << "double : -inf" << std::endl;
    }
}