#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# include "Brain.hpp"

class Animal
{
	protected:
		Brain		*brain_ptr;
		std::string		type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal&);
		Animal& operator= (const Animal&);
		void	makeSound() const;
		std::string		getType() const;
		void	ShowBrainIdea(int n);
};

#endif
