#include "Dog.hpp"

Dog::Dog()
{
	CLASS("Constructor", "Dog");
	this->type = "Dog";
	this->brain_ptr = new Brain();
}

Dog::~Dog()
{
	CLASS("Destructor", "Dog");
	delete this->brain_ptr;
	this->brain_ptr = NULL;
}

Dog::Dog(const Dog& other): Animal()
{
	CLASS("Constructor by copy", "Dog");
	this->type = other.type;
	this->brain_ptr = new Brain(*other.brain_ptr);
}

Dog& Dog::operator= (const Dog& other)
{
	CLASS("Operand = Constructor", "Dog");
	if (this == &other)
		return (*this);
	this->type = other.type;
	delete this->brain_ptr;
	this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}
