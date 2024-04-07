#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	name = "name";
	std::cout << "I was created in first constructor" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "I was created in second constructor: " << this->name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Was destructed: " << name << std::endl;
}