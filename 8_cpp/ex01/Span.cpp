	#include "Span.hpp"

Span::Span()
{
	CLASS("Constructor", "Span");
	this->_SizeMax = 0;
}

Span::Span(int N)
{
	CLASS("Constructor with input N", "Span");
	this->_SizeMax = N;
}

Span::~Span()
{
	CLASS("Destructor", "Span");
}

Span::Span(const Span& other)
{
	CLASS("Constructor by copy", "Span");
	if (this == &other)
		return ;
	this->_SizeMax = other._SizeMax;
	this->_V = other._V;
}

Span& Span::operator= (const Span& other)
{
	CLASS("Operand = Constructor", "Span");
	if (this == &other)
		return (*this);
	this->_SizeMax = other._SizeMax;
	this->_V = other._V;
	return (*this);
}

void Span::addNumber(int x)
{
	if (this->_V.size() == this->_SizeMax)
		throw Span::SizeMaxReached();
	this->_V.push_back(x);
}

size_t Span::shortestSpan()
{
	MyIt<std::vector<int> >	itC(this->_V.begin(), this->_V.end());
	size_t		shortest_span;

	if (this->_V.size() <= 1)
		throw Span::NotEnoughForSpan();
	std::sort(itC._Start, itC._End);
	shortest_span = UINT_MAX;
	for (itC._Index = itC._Start; itC._Index < itC._End; itC._Index++)
	{
		if ((size_t)(*(itC._Index + 1) - *itC._Index) < shortest_span)
			shortest_span = (int)*(itC._Index + 1) - (int)*itC._Index;
	}
	return (shortest_span);
}

size_t Span::longestSpan()
{
	MyIt<std::vector<int> >	itC(this->_V.begin(), this->_V.end());

	if (this->_V.size() <= 1)
		throw Span::NotEnoughForSpan();
	itC._Result = std::min_element(itC._Start, itC._End);
	itC._Result2 = std::max_element(itC._Start, itC._End);
	return (abs((long)*itC._Result2 - (long)*itC._Result));
}

void Span::fullFillRandom()
{
	std::vector<int>::iterator it;
	std::srand(std::time(NULL));

	it = this->_V.begin();
	while ((this->_V.size() != this->_SizeMax))
	{
		this->addNumber(std::rand() * ((std::rand() % 2) ? -1 : 1));
		it++;
	}
}

void Span::display()
{
	MyIt<std::vector<int> >	itC(this->_V.begin(), this->_V.end());
	
	std::cout << "Displaying all :\n" << std::endl;
	while (itC._Start < itC._End)
	{
		std::cout << *itC._Start << std::endl;
		itC._Start++;
	}
}

void Span::search(int n)
{
	MyIt<std::vector<int> >	itC(this->_V.begin(), this->_V.end());
	
	while (itC._Start < itC._End)
	{
		if (*itC._Start == n)
		{
			std::cout << n << " was found !" << std::endl;
		}
		itC._Start++;
	}
}