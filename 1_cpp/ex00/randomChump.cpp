#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	random_chump(name);

	random_chump.announce();
}