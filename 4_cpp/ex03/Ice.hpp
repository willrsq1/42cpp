#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	protected:

	public:
		Ice();
		~Ice();
		Ice(const Ice&);
		Ice& operator= (const Ice&);
		AMateria* clone() const;
};

#endif
