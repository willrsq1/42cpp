#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		Weapon			*my_weapon;
	public:
		HumanB(std::string);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon&);
};


#endif