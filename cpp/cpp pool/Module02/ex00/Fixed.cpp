#include "Fixed.hpp"

const int   Fixed::frac = 8;

Fixed::Fixed() : fp(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
   *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &src)
       // this->fp = src.getRawBits();
       this->setRawBits(src.getRawBits());
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fp);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRqwbits Call !" << std::endl;
    this->fp = raw;
}