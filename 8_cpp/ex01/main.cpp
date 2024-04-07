#include "Span.hpp"

int main()
{
		Span sp = Span(15);	
		// Span sp = Span(150000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
		std::cout <<"\n\n";


		sp.fullFillRandom();


		std::cout <<"\n\n After filling with randoms up to sizemax:\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
		sp.display();
		std::cout <<"\n\n";
		sp.search(9);
		sp.search(11);

		Span sp2 = Span(sp);
		std::cout << "longest: " << sp2.longestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;


	return 0;
}
