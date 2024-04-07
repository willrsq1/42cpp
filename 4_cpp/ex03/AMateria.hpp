#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
# ifndef CLASS
// # define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# define MATERIA_TAB_SIZE 4

class ICharacter;

class AMateria
{
	private:

	protected:
		std::string			_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria&);
		AMateria& operator= (const AMateria&);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		void use(ICharacter& target);
};
#endif
