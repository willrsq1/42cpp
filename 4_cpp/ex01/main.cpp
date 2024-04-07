# include "Cat.hpp"
# include "Dog.hpp"

int	main()
{

//test5
// Cat cat;
// cat.ShowBrainIdea(17);
// Cat cat2 = Cat(cat);
// cat2.ShowBrainIdea(17);
// Animal a = Animal(cat);

// a.ShowBrainIdea(12);
// //test4
// Animal **tab1 = new Animal*[10];
// for (size_t i = 0; i < 10; i++)
// {
// 	tab1[i] = new Animal();
// }
// for (size_t i = 0; i < 10; i++)
// {
// 	tab1[i]->makeSound();
// 	tab1[i]->ShowBrainIdea(i * 2);
// 	delete tab1[i];
// }
// delete[] tab1;

// //test1
// 	Cat *p = new Cat();

// 	p->ShowBrainIdea(10);
// 	delete p;

	
// //test2
// Animal **tab = new Animal*[10];
// for (size_t i = 0; i < 10; i++)
// {
// 	if (i % 2)
// 		tab[i] = new Dog();
// 	else
// 		tab[i] = new Cat();
// }
// for (size_t i = 0; i < 10; i++)
// {
// 	tab[i]->makeSound();
// 	tab[i]->ShowBrainIdea(i * 2);
// 	delete tab[i];
// }
// delete[] tab;


// //test3
// Dog **tabD = new Dog*[10];
// for (size_t i = 0; i < 10; i++)
// {
// 		tabD[i] = new Dog();
// }
// for (size_t i = 0; i < 10; i++)
// {
// 	tabD[i]->makeSound();
// 	tabD[i]->ShowBrainIdea(i);
// 	delete tabD[i];
// }
// delete[] tabD;
Cat R;
Cat L;
L = R;
Cat J(R);
return 0;
}