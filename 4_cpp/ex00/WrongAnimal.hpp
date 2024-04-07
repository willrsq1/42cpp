#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl

class WrongAnimal
{
	protected:
		std::string		type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator= (const WrongAnimal&);
		void	makeSound() const;
		std::string		getType() const;
};

#endif
