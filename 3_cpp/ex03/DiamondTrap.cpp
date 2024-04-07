#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
{
	std::cout << "Called Diamond Trap Constructor" << std::endl;
	this->_Name = "No_name";
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HitPoints = this->FragTrap::_HitPoints;
	this->_EnergyPoints = this->ScavTrap::_ScavEnergy;
	this->_AttackDamage = this->FragTrap::_AttackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Called Diamond Trap Constructor with Name Input" << std::endl;
	this->_Name = name;
	this->ClapTrap::_Name = name + "_clap_name";
	this->_HitPoints = this->FragTrap::_HitPoints;
	this->_EnergyPoints = this->ScavTrap::_ScavEnergy;
	this->_AttackDamage = this->FragTrap::_AttackDamage;
	std::cout << this->_HitPoints << " " << this->_EnergyPoints << " " << this->_AttackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called Diamond Trap Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Called Diamond Trap Copy Constructor" << std::endl;
	this->_Name = other._Name;
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	std::cout << "Called DiamondTrap Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_Name = other._Name;
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_Name << " and my grandfather ClapTrap's name is " << ClapTrap::show_Name() << std::endl;
}

void DiamondTrap::show_Hit_Points()
{
	std::cout << "DiamondTrap Hit Points = " << this->_HitPoints << std::endl;
}

void DiamondTrap::show_Energy_Points()
{
	std::cout << "DiamondTrap Energy Points = " << this->_EnergyPoints << std::endl;
}

void DiamondTrap::show_Attack_Damage()
{	
	std::cout << "DiamondTrap Attack Damage = " << this->_AttackDamage << std::endl;
}