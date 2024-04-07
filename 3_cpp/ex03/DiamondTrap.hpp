#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string			_Name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap&);
		DiamondTrap& operator= (const DiamondTrap& other);
		void	whoAmI();
		void	show_Hit_Points();
		void	show_Energy_Points();
		void	show_Attack_Damage();
};

#endif