#include "Ice.hpp"

Ice::Ice()
{
	CLASS("Constructor", "Ice");
	this->_type = "ice";
}

Ice::~Ice()
{
	CLASS("Destructor", "Ice");
}

Ice::Ice(const Ice&): AMateria()
{
	CLASS("Constructor by copy", "Ice");
}

Ice& Ice::operator= (const Ice& other)
{
	CLASS("Operand = Constructor", "Ice");
	if (this == &other)
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice);
}
