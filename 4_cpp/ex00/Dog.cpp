#include "Dog.hpp"

Dog::Dog()
{
	CLASS("Constructor", "Dog");
	this->type = "Dog";
}

Dog::~Dog()
{
	CLASS("Destructor", "Dog");
}

Dog::Dog(const Dog& other): Animal()
{
	CLASS("Constructor by copy", "Dog");
	this->type = other.type;
}

Dog& Dog::operator= (const Dog& other)
{
	CLASS("Operand = Constructor", "Dog");
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}