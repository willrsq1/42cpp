# include "Cat.hpp"
# include "Dog.hpp"

int	main()
{

//test5
Cat cat;
cat.ShowBrainIdea(17);
Cat cat2 = Cat(cat);
cat2.ShowBrainIdea(17);
cat2 = cat;
Cat cat3(cat);
cat2.ShowBrainIdea(17);
cat2 = Cat(cat3);
AAnimal *big = new Cat;
AAnimal *big2 = new Dog;

big->MakeSound();
delete big;
big = big2;
big->MakeSound();
delete big2;
// AAnimal hey;
// return 1;


// ANIMAL DECLARATION, CAUSING ERROR
// AAnimal a = AAnimal(cat);

// a.ShowBrainIdea(12);
//test4
// AAnimal **tab1 = new AAnimal*[10];
// for (size_t i = 0; i < 10; i++)
// {
// 	tab1[i] = new AAnimal();
// }
// for (size_t i = 0; i < 10; i++)
// {
// 	tab1[i]->MakeSound();
// 	tab1[i]->ShowBrainIdea(i * 2);
// 	delete tab1[i];
// }
// delete[] tab1;

//test1
	Cat *p = new Cat();

	p->ShowBrainIdea(10);
	delete p;

	
//test2
AAnimal **tab = new AAnimal*[10];
for (size_t i = 0; i < 10; i++)
{
	if (i % 2)
		tab[i] = new Dog();
	else
		tab[i] = new Cat();
}
for (size_t i = 0; i < 10; i++)
{
	tab[i]->MakeSound();
	tab[i]->ShowBrainIdea(i * 2);
	delete tab[i];
}
delete[] tab;
// return (0);


//test3
// Dog **tabD = new Dog*[10];
// for (size_t i = 0; i < 10; i++)
// {
// 		tabD[i] = new Dog();
// }
// for (size_t i = 0; i < 10; i++)
// {
// 	tabD[i]->MakeSound();
// 	tabD[i]->ShowBrainIdea(i);
// 	delete tabD[i];
// }
// delete[] tabD;
return 0;
}