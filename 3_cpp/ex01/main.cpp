# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main()
{
	ClapTrap* A = new ClapTrap("Jack");
	ScavTrap* B = new ScavTrap("Emma");
	ClapTrap* C = new ScavTrap("Fake");

	A->attack("jfjea");
	B->attack("emmama");
	C->attack("Anotheeer");
	A->takeDamage(5);
	B->takeDamage(5);
	B->guardGate();
	ScavTrap* D = B;
	D->attack("adol");
	delete A;
	delete B;
	delete C;

	ScavTrap H("Paul");
	H.attack("him");
	ClapTrap J("Deny");
	J.attack("blob");
}