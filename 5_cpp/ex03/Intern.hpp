#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif
# define INTERN_TAB_SIZE 3
# define PRESI "presidential request"
# define ROBO "robotomy request"
# define SHRUB "shrubbery request"

class Intern
{
	private:
		const char*		_Tab[INTERN_TAB_SIZE];
	protected:

	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator= (const Intern&);
		Form*			makeForm(std::string, std::string);
};

#endif
