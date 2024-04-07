#include "Base.hpp"

int		main()
{
	Base * ptr = generate();
	identify(ptr);
	identify(NULL);
	identify(*ptr);
	identify(NULL);
	delete ptr;

	for (size_t i = 0; i < 3; i++)
	{
		ptr = generate();
		std::cout << "New generation." << std::endl;
		identify(ptr);
		identify(*ptr);
		identify(*&*&*&*&*&*&*&*&*&*&*&*ptr);
		delete ptr;
	}
		
}
