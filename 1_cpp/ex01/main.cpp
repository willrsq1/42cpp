#include "Zombie.hpp"

int	main()
{
	Zombie	*zomb_hord;
	int		i = 0;
	int		N = 0;

	std::cout << "How many zombies do you want to create ?" << std::endl;
	std::cin >> N;
	if (!N)	{std::cerr << "Please input a positive number\n"; return 1;}
	std::cout << std::endl << "Creating a zombie horde of " << N << " zombies.\n" << std::endl;
	zomb_hord = zombieHorde(N, "Luffy");
	while (i < N)
	{
		zomb_hord->announce();
		i++;
	}
	delete[] zomb_hord;
	return (0);
}