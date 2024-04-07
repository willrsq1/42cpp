#include "Animal.hpp"

Animal::Animal()
{
	CLASS("Constructor", "Animal");
	this->type = "No type";
}

Animal::~Animal()
{
	CLASS("Destructor", "Animal");
}

Animal::Animal(const Animal& other)
{
	CLASS("Constructor by copy", "Animal");
	this->type = other.type;
}

Animal& Animal::operator= (const Animal& other)
{
	CLASS("Operand = Constructor", "Animal");
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "......" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}