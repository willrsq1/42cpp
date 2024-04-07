#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*Zombie_ptr;

	Zombie_ptr = new (std::nothrow) Zombie(name);
	if (Zombie_ptr == nullptr)
	{
		std::cerr << "New Allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (Zombie_ptr);
}