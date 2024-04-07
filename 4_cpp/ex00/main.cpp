# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int	main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete i;
delete j;
Dog d;
d.makeSound();
i = new Dog();
i->makeSound();
delete i;
i = new Cat();
i->makeSound();
delete i;

Animal **tab = new Animal*[10];
for (size_t i = 0; i < 10; i++)
{
	if (i % 2)
		tab[i] = new Dog();
	else
		tab[i] = new Cat();
}
for (size_t i = 0; i < 10; i++)
{
	tab[i]->makeSound();
	delete tab[i];
}
delete[] tab;


const WrongAnimal* Meta = new WrongAnimal();
const WrongCat* I = new WrongCat();
std::cout << I->getType() << " " << std::endl;
I->makeSound(); //will output the cat sound!
Meta->makeSound();
delete Meta;
delete I;
const WrongCat J;
J.makeSound();
const WrongAnimal* fake = new WrongCat();
fake->makeSound();
const Animal* one = new Cat();
one->makeSound();
delete fake;
delete one;
return 0;
}