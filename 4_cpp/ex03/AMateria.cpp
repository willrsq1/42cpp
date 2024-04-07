#include "AMateria.hpp"

AMateria::AMateria()
{
	CLASS("Constructor", "AMateria");
	this->_type = "No Type";
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	CLASS("Constructor with type input", "AMateria");
}

AMateria::~AMateria()
{
	CLASS("Destructor", "AMateria");
}

AMateria::AMateria(const AMateria&)
{
	CLASS("Constructor by copy", "AMateria");
}

AMateria& AMateria::operator= (const AMateria& other)
{
	CLASS("Operand = Constructor", "AMateria");
	if (this == &other)
		return (*this);
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* Heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}