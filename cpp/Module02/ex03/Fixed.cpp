
#include "Fixed.hpp"

const int   Fixed::frac = 8;

Fixed::Fixed() : fp(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    //std::cout << "Int constructor called" << std::endl;
    this->fp = n << this->frac;
}

Fixed::Fixed(const float n)
{
   // std::cout<< "Float constructor called" << std::endl;
    this->fp = roundf(n * (1 << this->frac));
}

Fixed::Fixed(const Fixed &copy)
{
   // std::cout << "Copy constructor called" << std::endl;
   *this = copy;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}


Fixed   &Fixed::operator=(const Fixed &src)
{
    //std::cout << "Copy assignment operator called " << std::endl;
    if (this != &src)
       // this->fp = src.getRawBits();
       this->setRawBits(src.getRawBits());
    return (*this);
}

bool    Fixed::operator>(Fixed fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool    Fixed::operator<(Fixed fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool    Fixed::operator>=(Fixed fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool    Fixed::operator<=(Fixed fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool    Fixed::operator==(Fixed fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool    Fixed::operator!=(Fixed fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

float   Fixed::operator+(Fixed fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float   Fixed::operator-(Fixed fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

float   Fixed::operator*(Fixed fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

float   Fixed::operator/(Fixed fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed   Fixed::operator++()
{
    this->fp++;
    return (*this);
}

Fixed   Fixed::operator--()
{
    this->fp--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->fp;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->fp;
    return (tmp);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
   if (a.toFloat() <= b.toFloat())
        return (a);
    else
        return (b); 
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return (a);
    else
        return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
   if (a.toFloat() >= b.toFloat())
        return (a);
    else
        return (b); 
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() >= b.toFloat())
        return (a);
    else
        return (b);
}

float Fixed::toFloat(void)const
{
    return ((float)this->fp / (float)(1 << this->frac));
}

int Fixed::toInt(void)const
{
    return (this->fp >> this->frac);
}

int Fixed::getRawBits(void) const
{
   // std::cout << "getRawBits member function called" << std::endl;
    return (this->fp);
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRqwbits Call !" << std::endl;
    this->fp = raw;
}

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}