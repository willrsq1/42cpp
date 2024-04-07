#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif
# include "Data.hpp"
# include <inttypes.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator= (const Serializer&);

	protected:

	public:
		~Serializer();
		static uintptr_t		serialize(Data* ptr);
		static Data* 			deserialize(uintptr_t raw);
};

#endif
