#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string			_Name;
		int					_HitPoints;
		int					_EnergyPoints;
		int					_AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap&);
		virtual ~ClapTrap();
		ClapTrap& operator= (const ClapTrap&);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string		show_Name();
};

#endif