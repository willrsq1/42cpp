#include "HumanB.hpp"

HumanB::HumanB(std::string the_name)
{
	name = the_name;
	my_weapon = NULL;
	std::cout << "Created Human B named " << name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destroyed Human B named " << name << std::endl;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (my_weapon != NULL)
		std::cout << my_weapon->getType() << std::endl;
	else
		std::cout << "fists, because they have no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon& the_weapon)
{
	my_weapon = &the_weapon;
}