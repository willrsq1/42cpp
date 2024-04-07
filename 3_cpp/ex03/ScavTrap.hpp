#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	protected:
		int		_ScavEnergy;
	public:
		ScavTrap();
		ScavTrap(std::string);
		~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator= (const ScavTrap& other);
		void attack(const std::string& target);
		void	guardGate();
};

#endif