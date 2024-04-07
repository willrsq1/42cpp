#include "Fixed.hpp"

int main( void ) {
	
// Fixed a;
// Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;

// b = a++;
// std::cout << a << " && " << b << std::endl;

// b = a--;
// std::cout << a << " && " << b << std::endl;

// Fixed const c = a;
// Fixed const d = b;
// std::cout << Fixed::max(--a, --b) << std::endl;
// std::cout << Fixed::max(c, d) << std::endl;

std::cout << "\n\n\nSubject tests\n\n" << std::endl;
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}