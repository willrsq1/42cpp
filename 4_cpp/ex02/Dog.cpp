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

Dog::Dog(const Dog& other): AAnimal()
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
	if (this->brain_ptr)
		delete this->brain_ptr;
	this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}

void Dog::ShowBrainIdea(int n)
{
	if (brain_ptr)
	{
		if (this->type == "Dog")
			std::cout << "I'm a Dog with the idea: ";
		brain_ptr->showIdea(n);
		return ;
	}
	else
		std::cout << "Just an Dog without ideas" << std::endl;
}

void Dog::MakeSound() const
{
	if (this->type == "Dog")
		std::cout << "Waf waf waf" << std::endl;
	else
		std::cout << "......" << std::endl;
}
