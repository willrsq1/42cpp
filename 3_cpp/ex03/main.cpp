#include "DiamondTrap.hpp"

int	main()
{
	//HIT POINT =  100 (frag)
	//ENERGY POINT = 50 scav
	//ATACK DMG = 30 frag
	DiamondTrap d("paul");

	d.beRepaired(0);
	d.attack("Jack");
	d.whoAmI();
	d.highFivesGuys();
	d.guardGate();
	d.show_Attack_Damage();
	d.show_Energy_Points();
	d.show_Hit_Points();
	ClapTrap *he = new DiamondTrap("jack");
	he->attack("emily");
	he->beRepaired(10);
	he->takeDamage(100);
	for (size_t i = 0; i < 50; i++)
	{
		he->beRepaired(0);
	}
	delete he;

}