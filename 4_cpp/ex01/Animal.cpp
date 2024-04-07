#include "Animal.hpp"

Animal::Animal()
{
	CLASS("Constructor", "Animal");
	this->type = "No type";
	this->brain_ptr = NULL;
}

Animal::~Animal()
{
	CLASS("Destructor", "Animal");
	if (this->brain_ptr)
		delete this->brain_ptr;
	this->brain_ptr = NULL;
}

Animal::Animal(const Animal& other)
{
	CLASS("Constructor by copy", "Animal");
	this->type = other.type;
	if (other.brain_ptr)
		this->brain_ptr = new Brain(*other.brain_ptr);
}

Animal& Animal::operator= (const Animal& other)
{
	CLASS("Operand = Constructor", "Animal");
	if (this == &other)
		return (*this);
	this->type = other.type;
	if (other.brain_ptr)
		this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void Animal::ShowBrainIdea(int n)
{
	if (brain_ptr)
	{
		if (this->type == "Cat")
			std::cout << "I'm a cat with the idea: ";
		else if (this->type == "Dog")
			std::cout << "I'm a Dog with the idea: ";
		brain_ptr->showIdea(n);
		return ;
	}
	else
		std::cout << "Just an animal without ideas" << std::endl;
}
