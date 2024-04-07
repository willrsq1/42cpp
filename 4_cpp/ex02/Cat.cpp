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

Cat::Cat(const Cat& other): AAnimal()
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
	if (this->brain_ptr)
		delete this->brain_ptr;
	this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}

void Cat::ShowBrainIdea(int n)
{
	if (brain_ptr)
	{
		if (this->type == "Cat")
			std::cout << "I'm a cat with the idea: ";
		brain_ptr->showIdea(n);
		return ;
	}
	else
		std::cout << "Just an Cat without ideas" << std::endl;
}

void Cat::MakeSound() const
{
	if (this->type == "Cat")
		std::cout << "Meooooooow" << std::endl;
	else
		std::cout << "......" << std::endl;
}
