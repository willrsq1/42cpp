#include "Array.hpp"

int main( void ) {
	std::cout << "Basic tests\n";
	Array<int>	*m = new Array<int>(0);
	std::cout << "m has a size of: " << m->getSize() << std::endl;
	delete m;
	Array<int>	*p = new Array<int>(10);
	
	for (size_t i = 0; i < (*p).getSize(); i++)
	{
		(*(p))[i] = 42;
		std::cout << "Element [" << i << "] is : " << (*(p))[i]<<std::endl;
	}

	try 
	{
		const Array<int> a(5);
		Array<int> b(5);
		// a[1] = 27;
		b[1] = 27; 
		(*p)[5] = 2;
		std::cout << "Modified element is now: ";
		std::cout << a[1] << "; and ";
		std::cout << b[1] << "; and " << (*p)[5] << std::endl;
		(*p)[17];
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
// 	std::cout << "Copy tests\n";
// 	Array<int>	a(5);
// 	for (size_t i = 0; i < a.getSize(); i++)
// 	{
// 		(a)[i] = 27;
// 		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
// 	}
// 	a = *p;
// 	for (size_t i = 0; i < a.getSize(); i++)
// 	{
// 		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
// 		a[i] = -1306;
// 	}
// 	std::cout << "Post modif A\n";

// 	for (size_t i = 0; i < (*p).getSize(); i++)
// 	{
// 		// (*(p))[i] = 42;
// 		std::cout << "Element [" << i << "] is : " << (*(p))[i]<<std::endl;
// 	}
	
// 	std::cout << "P is not modified !\n";


// //test modifying B who was copy constructed of a
// 	const Array<int> B = Array<int>(a);

// 	for (size_t i = 0; i < (B).getSize(); i++)
// 	{
// 		std::cout << "Element [" << i << "] is : " << (B)[i]<<std::endl;
// 		// B[i] = 17072000;
// 	}
// 	std::cout << "B was modifed\n";
// 	for (size_t i = 0; i < (B).getSize(); i++)
// 	{
// 		std::cout << "Element [" << i << "] is : " << (B)[i]<<std::endl;
// 	}
// 	std::cout << "A is now:\n";
// 	for (size_t i = 0; i < a.getSize(); i++)
// 	{
// 		(a)[i] = 15;
// 		std::cout << "Element [" << i << "] is : " << (a)[i]<<std::endl;
// 	}
// 	// (*p)[111];

// 	Array<std::string> S(5);
// 	for (size_t i = 0; i < S.getSize(); i++)
// 	{
// 		std::cout << "S[" << i << "] = " << S[i] << std::endl;
// 	}
	
	delete p;

return 0;
}
