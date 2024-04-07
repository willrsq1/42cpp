#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	CLASS("Constructor", "WrongAnimal");
	this->type = "IM A WRONG ANIMAL";
}

WrongAnimal::~WrongAnimal()
{
	CLASS("Destructor", "WrongAnimal");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	CLASS("Constructor by copy", "WrongAnimal");
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	CLASS("Operand = Constructor", "WrongAnimal");
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Wrong Animal noise idk idc*" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}