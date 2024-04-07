#include "iter.hpp"
#include "../ex00/whatever.hpp"

int main( void ) {
	int	L[] = {1, 2, 3, 4};
	std::string S[] = {"Hello", "World", "My", "Name", "is"}; 
	const char* SS[] = {"Hello", "World", "My", "Name", "is"}; 

	::iter(L, 4, &print);
	::iter(L, 4, &incr);
	::iter(L, 4, &print);

	std::cout << "With tab of strings: \n\n";

	::iter(S, 5, &print);
	::iter(S, 5, &incr);
	::iter(S, 5, &incr);
	::iter(S, 5, &incr);
	::iter(S, 5, &incr);
	::iter(S, 5, &print);
	::iter(S, 5, &print);
	std::cout << "With tab of char *: \n\n";

	::iter(SS, 5, &print);
	::iter(SS, 5, &incr);
	::iter(SS, 5, &incr);
	::iter(SS, 5, &print);
	::iter(SS, 5, &decr);
	::iter(SS, 5, &print);
	::iter(SS, 5, &incr);
	::iter(SS, 5, &print);
	
return 0;
}
