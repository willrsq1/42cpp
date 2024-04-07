#include "Base.hpp"

Base::~Base()
{
	CLASS("Destructor", "Base");
}

Base* generate(void)
{
	short	option = std::clock() % 3;

	if (option == 0)
		return ((Base*)new A);
	else if (option == 1)
		return ((Base*)new B);
	else if (option == 2)
		return ((Base*)new C);
	return (NULL);
}

void identify(Base* p)
{
	std::cout << "This is a ptr to a [" << BLUE;
	if ((dynamic_cast<A*>(p)))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << RED << "NON DERIVED FROM BASE/NON EXISTANT/NULL";
	std::cout << RESET_COLOR << "] class. (Observerved by" << BLUE << " ptr" << RESET_COLOR << ")" << std::endl;
}

void identify(Base& p)
{
	Base a;
	
	std::cout << "This is a ptr to a [" << BLUE;
	try
	{
		a = (dynamic_cast<A&>(p));
		std::cout << "A";
	}
	catch (...)
	{
		try
		{
			a = (dynamic_cast<B&>(p));
			std::cout << "B";
		}
		catch (...)
		{
			try
			{
				a = (dynamic_cast<C&>(p));
				std::cout << "C";
			}
			catch (...)
			{
				std::cout << RED << "NON DERIVED FROM BASE/NON EXISTANT";
			}
		}
	}
	std::cout << RESET_COLOR << "] class. (Observerved by" << BLUE << " reference" << RESET_COLOR << ")" << std::endl;
}
