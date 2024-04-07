#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	CLASS("Constructor", "WrongCat");
}

WrongCat::~WrongCat()
{
	CLASS("Destructor", "WrongCat");
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal()
{
	CLASS("Constructor by copy", "WrongCat");
	this->type = other.type;
}

WrongCat& WrongCat::operator= (const WrongCat& other)
{
	CLASS("Operand = Constructor", "WrongCat");
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "*Wrong Cat noisebark bark WOUf wouf" << std::endl;
}
