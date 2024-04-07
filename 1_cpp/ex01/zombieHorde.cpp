#include "Zombie.hpp"

#define MAX_ZOMBIES 1000

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*Zombie_tab;
	int	i;

	if (N > MAX_ZOMBIES)	{std::cerr << "Input smaller number, has to be < " << MAX_ZOMBIES << std::endl; return NULL;}
	Zombie_tab = new (std::nothrow) Zombie[N];
	if (Zombie_tab == NULL)
	{
		std::cerr << "New Allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < N)
	{
		Zombie_tab[i].set_name(name);
		i++;
	}
	return (Zombie_tab);
}