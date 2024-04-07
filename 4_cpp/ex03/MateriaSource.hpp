#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		void	setNull();
		AMateria*				_Tab[MATERIA_TAB_SIZE];
	protected:

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator= (const MateriaSource&);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
