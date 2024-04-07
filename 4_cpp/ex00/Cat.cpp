#include "Cat.hpp"

Cat::Cat()
{
	CLASS("Constructor", "Cat");
	this->type = "Cat";
}

Cat::~Cat()
{
	CLASS("Destructor", "Cat");
}

Cat::Cat(const Cat& other): Animal()
{
	CLASS("Constructor by copy", "Cat");
	this->type = other.type;
}

Cat& Cat::operator= (const Cat& other)
{
	CLASS("Operand = Constructor", "Cat");
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}