#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <new>

class Zombie
{
	std::string		name;

	public :
		void announce( void );
		void set_name(std::string);
		Zombie();
		Zombie(std::string);
		~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif