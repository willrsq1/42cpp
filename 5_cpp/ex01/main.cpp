#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat bob("Bob", 30);
		Form		form("Permis", 15, 12);
		std::cout << bob << std::endl << form << std::endl;
		Form	truc("jaques", 100, 100);
		Form machin = truc;
		machin.beSigned(bob);
		machin.beSigned(bob);
		machin = form;
		machin.beSigned(bob);
		// form.beSigned(bob);
		while (bob.getRank() < 150)
			bob.decrGrade();
		machin.beSigned(bob);
		Bureaucrat john = bob;
		while (1)
			bob.incrGrade();
		std::cout << john << std::endl << bob << std::endl;
		while (john.getRank() > truc.getSignGrade())
			john.incrGrade();
		// john.decrGrade();
		truc.beSigned(john);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET_COLOR << '\n';
		return (1);
	}
	return (0);
}