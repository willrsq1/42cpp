# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

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

	ScavTrap	c("Chuck");
	c.attack("Franck");
	c.beRepaired(10);
	ScavTrap	d;
	d = ScavTrap("Daniel");
	d.guardGate();
	d.guardGate();
	d.takeDamage(100);
	d.guardGate();
	ScavTrap* M = new ScavTrap("Mallocated");
	M->guardGate();
	M->beRepaired(1000);
	M->attack("someone");
	delete M;
	FragTrap f("Franck");
	f.attack("Jullll");
	f.beRepaired(10);
	FragTrap l = f;
	f.beRepaired(10);
	l.takeDamage(5);
	l.highFivesGuys();
	l.highFivesGuys();
	ScavTrap j("h");
	j.attack("Jon");
	j.takeDamage(100);
	f.takeDamage(100);
	f.highFivesGuys();
	FragTrap* J = new FragTrap[5]();
	delete []J;

	l.takeDamage(100);
	f.highFivesGuys();


	//IMPORTANT TESTS
	ClapTrap *guy = new ScavTrap("Emma");

	guy->attack("la sal");

	delete guy;
	guy = new FragTrap("Haaaaalloo");
	guy->attack("aaaaa");
	guy->beRepaired(100);
	delete guy;
}