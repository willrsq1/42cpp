#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <map>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class Myex: public std::exception
{
	const char* what() const throw(){
		return ("exception: number not found");
	}
};

template<typename T>
	class ItEasyfind
{
	public:
	typename T::iterator		_Start;
	typename T::iterator		_End;
	typename T::iterator		_Result;
	ItEasyfind(typename T::iterator start, typename T::iterator end): _Start(start), _End(end){}
	~ItEasyfind() {}
	int					 get_Dist() const
	{
		return std::distance(_Start, _Result);
	}
};



	template<typename T>
void	easyfind(T cont, const int nb)
{
	ItEasyfind<T>		my_it(cont.begin(), cont.end());
	
	my_it._Result = std::find(my_it._Start, my_it._End, nb);
	if (my_it._Result != my_it._End)
		std::cout << "result = " << my_it.get_Dist() <<  std::endl;
	else
	{
		std::cerr << "for nb [" << nb << "]: ";
		throw ::Myex();
	}
}

#endif
