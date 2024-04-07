#include "HumanA.hpp"

HumanA::HumanA(std::string the_name, Weapon& the_weapon): my_weapon(the_weapon)
{
	name = the_name;
	std::cout << "Created Human A named " << name << " with weapon: " << my_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destroyed Human A named " << name << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << my_weapon.getType() << std::endl;
}
