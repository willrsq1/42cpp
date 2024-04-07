#include "Zombie.hpp"

int	main()
{
	Zombie	zomb_one("Paul");
	Zombie	*zomb_two;
	Zombie	zomb_three;

	zomb_two = newZombie("Jack");
	zomb_three.set_name("Marijoiz");
	zomb_one.announce();
	zomb_two->announce();
	zomb_three.announce();
	randomChump("Paulette");
	delete zomb_two;
	return (0);
}