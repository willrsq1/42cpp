#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

# define LOG(x) std::cout << x << std::endl

int main()
{

IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
// return 0;
	//leaks tests
	ICharacter*	player = new Character("Paul");
	ICharacter*	enemy = new Character("Ennemy");
	AMateria*	ice = new Ice;
	AMateria*	cure = new Cure;

	player->equip(new Ice);
	player->equip(new Cure);
	LOG(player->getName());

	player->use(3, *enemy);
	player->use(0, *enemy);

	player->equip(ice->clone()); //any equiped materia will be freed by the Character, even if its full
	player->equip(cure->clone());
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		player->use(i, *enemy);
		player->unequip(i);
	}
	for (size_t i = 0; i < MATERIA_TAB_SIZE * 10; i++)
	{
		player->equip(i % 2 ? ice->clone() : cure->clone());
		if (i % 4 == 0)
			player->unequip(i % 4);
		player->use(i % 4, *enemy);
	}
	std::cout << "Hey\n" << std::endl;
	Character b("Jack");

	for (size_t i = 0; i < 20; i++)
	{
		b.equip(new Cure);
	}
	
	Character a = b;
	b = b;
	b = a;
	Cure	cure2;
	std::cout << "\n\n\n\n";
	Character c = b;
	c = a;
	ICharacter*	d = new Character("dylan");
	LOG(d->getName());




	//copy works and replaces old metaria:
	Character	m;
	Character	n;
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		m.equip(ice->clone());
		n.equip(cure->clone());
	}
	m = n;
	Character bad_guy("Bad Guy");
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		m.use(i, *enemy);
		n.unequip(i);
		n.equip(ice->clone());
		n.use(i, bad_guy);
	}
	Character o = m;
	for (size_t i = 0; i < MATERIA_TAB_SIZE; i++)
	{
		o.use(i, *enemy);
		m.use(i, *enemy);
		if (i == 1)
			o = n;
	}
	delete d;
	delete ice;
	delete cure;
	delete player;
	delete enemy;
	return (0);
}