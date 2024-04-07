#include "Fixed.hpp"

const int	Fixed::nb_fract_bits = 8;

Fixed::Fixed()
{
	this->fixed_value = 0;
	// std::cout << "Default constructor [Fixed] called" << std::endl;
}

Fixed::Fixed(const int a)
{
	// std::cout << "Int constructor [Fixed] called" << std::endl;
	this->setRawBits((int)(a * (1 << this->nb_fract_bits)));
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor [Fixed] called" << std::endl;
	this->setRawBits((float)roundf((f * (1 << this->nb_fract_bits))));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor [Fixed] called" << std::endl;
}

Fixed::Fixed(const Fixed& old)
{
	// std::cout << "Copy constructor [Fixed] called" << std::endl;
	*this = old;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "GetRawBits member function [Fixed] called" << std::endl;
	return (this->fixed_value);
}
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "SetRawBits member function [Fixed] called" << std::endl;
	this->fixed_value = raw;
}

float	Fixed::toFloat(void) const
{	
	// std::cout << "toFloat member function [Fixed] called" << std::endl;
	return ((float)((float)this->fixed_value / (1 << this->nb_fract_bits)));
}

int		Fixed::toInt(void) const
{
	// std::cout << "toInt member function [Fixed] called" << std::endl;
	return ((int)(this->fixed_value >> this->nb_fract_bits));
}



std::ostream& operator<<(std::ostream& outstream, const Fixed& x)
{
	outstream << x.toFloat();
	return (outstream);
}

//comparison

Fixed& Fixed::operator= (const Fixed& other)
{
	// std::cout << "Copy assignement operator [Fixed] called" << std::endl;
	this->fixed_value = other.getRawBits();
	return (*this);
}

bool	Fixed::operator> (const Fixed& other) const
{
	return (this->fixed_value > other.fixed_value);
}

bool	Fixed::operator>= (const Fixed& other) const
{
	return (this->fixed_value >= other.fixed_value);
}

bool	Fixed::operator< (const Fixed& other) const
{
	return (this->fixed_value < other.fixed_value);
}

bool	Fixed::operator<= (const Fixed& other) const
{
	return (this->fixed_value <= other.fixed_value);
}

bool	Fixed::operator== (const Fixed& other) const
{
	return (this->fixed_value == other.fixed_value);
}

bool	Fixed::operator!= (const Fixed& other) const
{
	return (this->fixed_value != other.fixed_value);
}

//arithmetic

Fixed	Fixed::operator+ (const Fixed& other) const
{

	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator- (const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator* (const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/ (const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//increment

Fixed	Fixed::operator++ ()
{
	this->fixed_value += 1;
	return (Fixed(this->toFloat()));
}

Fixed	Fixed::operator++ (int post)
{
	Fixed	temp = *this;
	if (post == 0)
		post = 0;
	this->fixed_value += 1;
	return (temp);
}

Fixed	Fixed::operator-- ()
{
	this->fixed_value -= 1;
	return (Fixed(this->toFloat()));
}

Fixed	Fixed::operator-- (int post)
{
	Fixed	temp = *this;
	if (post == 0)
		post = 0;
	this->fixed_value -= 1;
	return (temp);
}


//min max

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
