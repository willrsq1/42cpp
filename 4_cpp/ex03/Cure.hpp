#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	protected:

	public:
		Cure();
		~Cure();
		Cure(const Cure&);
		Cure& operator= (const Cure&);
		AMateria* clone() const;
};

#endif
