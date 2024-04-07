#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type): type(weapon_type)
{
	std::cout << "Created Weapon: " << weapon_type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destroyed Weapon: " << type << std::endl;
}

const std::string&		Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
