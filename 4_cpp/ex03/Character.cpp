#include "Character.hpp"

Character::Character()
{
	CLASS("Constructor", "Character");
	this->_Name = "No Name";
	this->_List = NULL;
	this->setNull();
}

Character::Character(std::string name)
{
	CLASS("Constructor with input name", "Character");
	this->_List = NULL;
	this->_Name = name;
	this->setNull();
}

Character::~Character()
{
	CLASS("Destructor", "Character");
	this->deleteMaterias();
}

Character::Character(const Character& other)
{
	CLASS("Constructor by copy", "Character");
	this->_Name = other._Name;
	this->setNull();
	this->_List = NULL;
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		if (other._Tab[i])
		{
			this->equip(other._Tab[i]->clone());
		}
	}
}

Character& Character::operator= (const Character& other)
{
	CLASS("Operand = Constructor", "Character");
	if (this == &other)
		return (*this);
	this->_Name = other._Name;
	if (this->_List)
		this->deleteMaterias();
	this->setNull();
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		if (other._Tab[i])
		{
			this->equip(other._Tab[i]->clone());
		}
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	newMateria(m);
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		if (this->_Tab[i] == NULL)
		{
			this->_Tab[i] = m;
			return ;
		}
	}
}

void Character::setNull()
{
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		this->_Tab[i] = NULL;
	}
}

void Character::use(int index, ICharacter& target)
{
	if (index < 0 || index >= MATERIA_TAB_SIZE || !this->_Tab[index])
		return ;
	this->_Tab[index]->use(target);
}

void Character::unequip(int index)
{
	if (index < 0 || index >= MATERIA_TAB_SIZE)
		return ;
	if (this->_Tab[index] == NULL)
		return ;
	this->_Tab[index] = NULL;
}

void Character::newMateria(AMateria* ptr)
{
	t_lst_Materia*				_lst;
	static t_lst_Materia*		_lastlst;

	_lst = new t_lst_Materia;
	_lst->_ptrMateria = ptr;
	_lst->next = NULL;
	if (!this->_List)
	{
		this->_List = _lst;
		_lastlst = this->_List;
		return ;
	}
	_lastlst->next = _lst;
	_lastlst = _lst;

}
void Character::deleteMaterias()
{
	t_lst_Materia*		temp;

	while (this->_List)
	{
		temp = this->_List->next;
		delete this->_List->_ptrMateria;
		delete this->_List;
		this->_List = temp;
	}
	this->_List = NULL;
}

std::string const & Character::getName() const
{
	return (this->_Name);
}