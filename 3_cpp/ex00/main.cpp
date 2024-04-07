# include "ClapTrap.hpp"

int	main()
{
	ClapTrap A = ClapTrap("Jack");
	ClapTrap B("BOB");

	A.attack("BOB");
	B.takeDamage(3);
	A.beRepaired(10);
	int	i = 11;
	while (--i){
		B.attack("Jaki");	B.beRepaired(1);}
}