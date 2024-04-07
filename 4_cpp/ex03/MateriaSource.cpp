#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	CLASS("Constructor", "MateriaSource");
	setNull();
}

MateriaSource::~MateriaSource()
{
	CLASS("Destructor", "MateriaSource");
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	CLASS("Constructor by copy", "MateriaSource");
	setNull();
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		this->_Tab[i] = other._Tab[i];
	}
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	CLASS("Operand = Constructor", "MateriaSource");
	if (this == &other)
		return (*this);
	setNull();
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		this->_Tab[i] = other._Tab[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* learnedMateria)
{
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		if (!this->_Tab[i])
		{
			this->_Tab[i] = learnedMateria;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		if (!this->_Tab[i])
			return (NULL);
		if (this->_Tab[i]->getType() == type)
			return (this->_Tab[i]->clone());
	}
	return (NULL);
}

void MateriaSource::setNull()
{
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		this->_Tab[i] = NULL;
	}
}
