#include "Fixed.hpp"

const int	Fixed::nb_fract_bits = 8;

Fixed::Fixed()
{
	this->fixed_value = 0;
	std::cout << "Default constructor [Fixed] called" << std::endl;
}

Fixed::Fixed(const int a)
{
	std::cout << "Int constructor [Fixed] called" << std::endl;
	this->setRawBits((int)(a * (1 << this->nb_fract_bits)));
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor [Fixed] called" << std::endl;
	this->setRawBits((float)roundf((f * (1 << this->nb_fract_bits))));
}

Fixed::~Fixed()
{
	std::cout << "Destructor [Fixed] called" << std::endl;
}

Fixed::Fixed(const Fixed& old)
{
	std::cout << "Copy constructor [Fixed] called" << std::endl;
	*this = old;
}

Fixed& Fixed::operator= (const Fixed& old)
{
	std::cout << "Copy assignement operator [Fixed] called" << std::endl;
	this->fixed_value = old.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function [Fixed] called" << std::endl;
	return (this->fixed_value);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "SetRawBits member function [Fixed] called" << std::endl;
	this->fixed_value = raw;
}

float	Fixed::toFloat(void) const
{	
	return ((float)((float)this->fixed_value / (1 << this->nb_fract_bits)));
}

int		Fixed::toInt(void) const
{
	return ((int)(this->fixed_value >> this->nb_fract_bits));
}
std::ostream& operator<<(std::ostream& outstream, const Fixed& x)
{
	outstream << x.toFloat();
	return (outstream);
}
