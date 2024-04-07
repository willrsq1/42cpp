#include "Harl.hpp"

int	main()
{
	Harl	man;

	man.complain("DEBUG");
	std::cout << std::endl;
	man.complain("INFO");
	std::cout << std::endl;
	man.complain("WARNING");
	std::cout << std::endl;
	man.complain("ERROR");
	std::cout << std::endl;
	man.complain("BAD");
}