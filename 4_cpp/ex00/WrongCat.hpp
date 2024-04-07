#ifndef WRONGCat_HPP
# define WRONGCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat&);
		WrongCat& operator= (const WrongCat&);
		void	makeSound() const;
};

#endif