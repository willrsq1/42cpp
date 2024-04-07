#include "Fixed.hpp"

const int	Fixed::nb_fract_bits = 8;

Fixed::Fixed()
{
	this->fixed_value = 0;
	std::cout << "Default constructor [Fixed] called" << std::endl;
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
	if (*this == old)
		return ;
	this->fixed_value = old.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function [Fixed] called" << std::endl;
	return (fixed_value);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "SEEEEETRawBits member function [Fixed] called" << std::endl;
	fixed_value = raw;
}