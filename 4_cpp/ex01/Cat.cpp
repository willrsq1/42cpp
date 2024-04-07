#include "Cat.hpp"

Cat::Cat()
{
	CLASS("Constructor", "Cat");
	this->type = "Cat";
	this->brain_ptr = new Brain();
}

Cat::~Cat()
{
	CLASS("Destructor", "Cat");
	delete this->brain_ptr;
	this->brain_ptr = NULL;
}

Cat::Cat(const Cat& other): Animal()
{
	CLASS("Constructor by copy", "Cat");
	this->type = other.type;
	this->brain_ptr = new Brain(*other.brain_ptr);
}

Cat& Cat::operator= (const Cat& other)
{
	CLASS("Operand = Constructor", "Cat");
	if (this == &other)
		return (*this);
	this->type = other.type;
	delete this->brain_ptr;
	this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}
