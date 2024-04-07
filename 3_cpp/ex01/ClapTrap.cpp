#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Called ClapTrap Constructor" << std::endl;
	this->_Name = "No_name";
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	this->_HitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Called ClapTrap Constructor with Name Input" << std::endl;
	this->_Name = name;
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	this->_HitPoints = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called ClapTrap Destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Called ClapTrap Copy Constructor" << std::endl;
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	std::cout << "Called ClapTrap Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_Name = other._Name;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	this->_HitPoints = other._HitPoints;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "ClapTrap " << this->_Name << " is dead. It can't attack." << std::endl;
		return ;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cerr << "ClapTrap " << this->_Name << " is out of energy. It can't attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << " causing " << _AttackDamage << " points of damage." << std::endl;
	this->_EnergyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "ClapTrap " << this->_Name << " is already dead. It can't take more damage." << std::endl;
		return ;
	}
	this->_HitPoints -= amout;
	std::cout << "ClapTrap " << this->_Name << " took " << amout << " points of damage, causing its Hit Points to drop to ";
	std::cout << this->_HitPoints << "." << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << "ClapTrap " << this->_Name << " died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_HitPoints <= 0)
	{
		std::cerr << "ClapTrap " << this->_Name << " is already dead. It can't take repair iteself." << std::endl;
		return ;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cerr << "ClapTrap " << this->_Name << " is out of energy. It can't repair itself." << std::endl;
		return ;
	}
	this->_HitPoints += amout;
	std::cout << "ClapTrap " << this->_Name << " heals iself of " << amout << " Hit Points. He now has " << this->_HitPoints << " Hit Points." << std::endl;
	this->_EnergyPoints -= 1;
}
