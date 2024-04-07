#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
	std::cout << "Called ScavTrap Constructor" << std::endl;
	this->_Name = "no name";
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_ScavEnergy = 50;
	this->_HitPoints = 100;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Called ScavTrap Constructor with Name Input" << std::endl;
	this->_Name = name;
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_ScavEnergy = 50;
	this->_HitPoints = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Called ScavTrap Destructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "Called ScavTrap Copy Constructor" << std::endl;
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& other)
{
	std::cout << "Called ScavTrap Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "ScavTrap " << this->_Name << " is dead. It can't attack." << std::endl;
		return ;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cerr << "ScavTrap " << this->_Name << " is out of energy. It can't attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << " causing " << this->_AttackDamage << " points of damage. <--- IM A SCAVTRAP" << std::endl;
	this->_EnergyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "ScavTrap " << this->_Name << " is dead. It can't enter Gate Keeper mode." << std::endl;
		return ;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cerr << "ScavTrap " << this->_Name << " is out of energy. It can't enter Gate Keeper mode." << std::endl;
		return ;
	}
	this->_EnergyPoints -= 1;
	std::cout << "ScavTrap " << this->_Name << " has entered the mode: Gate Keeper." << std::endl;
}
