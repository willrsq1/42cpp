#ifndef C_HPP
# define C_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# include "Base.hpp"

class C: public Base
{
	private:

	protected:

	public:
};

#endif
