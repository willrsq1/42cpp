#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits.h>
// # include <bits/stdc++.h>
# include <cmath>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# define RED	"\033[1;31m"
# define RESET_COLOR "\033[0m"
# define GREEN	"\033[1;32m"

# define ERR(x) std::cerr << RED << x << RESET_COLOR << std::endl
# define CHAR(x) std::cout << "char: '" << x << "'" << std::endl
# define INT(x) std::cout << "int: " << x << std::endl
# define FLOAT(x, y) std::cout << "float: " << x << y << std::endl
# define DOUBLE(x, y) std::cout << "double: " << x << y << std::endl

class ScalarConverter
{
	private:
		ScalarConverter();

	protected:

	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator= (const ScalarConverter&);
		static void		convert(const std::string&);
		static void		typeChar(const std::string &);
		static void		typeInt(const std::string &);
		static void		typeFloat(const std::string &);
		static void		typeDouble(const std::string &);
		static bool		isFloat(const std::string & input);
		static bool		isDouble(const std::string & input);
		static bool		isInt(const std::string & input);
		static bool		isChar(const std::string & input);
};

#endif
