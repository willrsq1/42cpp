#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat: public AAnimal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat& operator= (const Cat&);
		void	ShowBrainIdea(int n);
		void	MakeSound() const;
};

#endif