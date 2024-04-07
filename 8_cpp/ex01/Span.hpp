#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# include <vector>
# include <algorithm>
# include <map>
# include <cstdlib>
# include <ctime>
# include <limits.h>

	template<typename T>
class MyIt
{
	public:
	typename T::iterator		_Start;
	typename T::iterator		_End;
	typename T::iterator		_Result;
	typename T::iterator		_Result2;
	typename T::iterator		_Index;
	MyIt(typename T::iterator start, typename T::iterator end): _Start(start), _End(end){}
	~MyIt() {}
};

class Span
{
	private:
		std::vector<int>			_V;
		unsigned int				_SizeMax;
		Span();
	protected:

	public:
		Span(int);
		~Span();
		Span(const Span&);
		Span& operator= (const Span&);
		void					addNumber(int);
		size_t					shortestSpan();
		size_t					longestSpan();
		void					fullFillRandom();
		void					display();
		void					search(int n);

		
	class SizeMaxReached: public std::exception
	{
		const char* what() const throw(){
			return ("The vector already contains its max allowed nb of elements.");
		}
	};
	class NotEnoughForSpan: public std::exception
	{
		const char* what() const throw(){
			return ("The vector has too few elements to calculate its spans.");
		}
	};
};


#endif
