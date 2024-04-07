#include "Cure.hpp"

Cure::Cure()
{
	CLASS("Constructor", "Cure");
	this->_type = "cure";
}

Cure::~Cure()
{
	CLASS("Destructor", "Cure");
}

Cure::Cure(const Cure&): AMateria()
{
	CLASS("Constructor by copy", "Cure");
}

Cure& Cure::operator= (const Cure& other)
{
	CLASS("Operand = Constructor", "Cure");
	if (this == &other)
		return (*this);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure);
}
