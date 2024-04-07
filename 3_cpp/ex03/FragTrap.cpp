#include "FragTrap.hpp"


FragTrap::FragTrap(/* args */)
{
	std::cout << "Called FragTrap Constructor" << std::endl;
	this->_Name = "No_name";
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Called FragTrap Constructor with Name Input" << std::endl;
	this->_Name = name;
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap Destructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "Called FragTrap Copy Constructor" << std::endl;
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
}

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << "Called FragTrap Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "FragTrap " << this->_Name << " is dead. It can't ask for high fives." << std::endl;
		return ;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cerr << "FragTrap " << this->_Name << " is out of energy. It can't ask for high fives." << std::endl;
		return ;
	}
	this->_EnergyPoints -= 1;
	std::cout << "Hey guys ! I'm " << this->_Name << ", will you high-five me ?" << std::endl;
}
