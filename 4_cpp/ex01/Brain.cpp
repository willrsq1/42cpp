#include "Brain.hpp"

Brain::Brain()
{
	CLASS("Constructor", "Brain");
	fill_ideas();
}

Brain::~Brain()
{
	CLASS("Destructor", "Brain");
}

Brain::Brain(const Brain& other)
{
	CLASS("Constructor by copy", "Brain");
	int	i = -1;
	while (++i < SIZE_TAB)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator= (const Brain& other)
{
	CLASS("Operand = Constructor", "Brain");
	if (this == &other)
		return (*this);
	int	i = -1;
	while (++i < SIZE_TAB)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

void Brain::fill_ideas()
{
	int i = -1;
	while (++i < SIZE_TAB)
		this->ideas[i] = "Good idea :)";
}

void Brain::showIdea(int n)
{
	if (n < 0 || n >= SIZE_TAB)
	{
		std::cerr << "Idea nb is out of range. Has to be from 0 to " << SIZE_TAB << std::endl;
		return ;
	}
	std::cout << "The idea nb " << n << " is " << this->ideas[n] << std::endl; 
}
