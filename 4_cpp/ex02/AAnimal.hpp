#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# include "Brain.hpp"

class AAnimal
{
	protected:
		Brain		*brain_ptr;
		std::string		type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal&);
		AAnimal& operator= (const AAnimal&);
		virtual void	MakeSound() const = 0;
		virtual std::string		getType() const;
		virtual void	ShowBrainIdea(int n) = 0;
};

#endif
