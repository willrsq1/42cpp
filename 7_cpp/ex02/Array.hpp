#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

	template<typename T>
class Array
{
	private:
		T*				_Tab;
		unsigned int*	_Size;
	protected:

	public:
		Array();
		Array(unsigned int);
		~Array();
		Array(const Array&);
		Array& operator= (const Array&);
		T& operator[] (size_t i);
		T const & operator[] (size_t i) const;
		unsigned int	getSize() const{		
			return (*this->_Size);
		}

		class IndexOutOfBounds: public std::exception
	{
		const char* what() const throw();
	};
};

# include "Array.tpp"

#endif
