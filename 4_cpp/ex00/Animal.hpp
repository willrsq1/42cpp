#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl

class Animal
{
	protected:
		std::string		type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal&);
		Animal& operator= (const Animal&);
		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif
