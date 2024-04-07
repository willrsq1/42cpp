#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include <fstream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class ShrubberyCreationForm: public Form
{
	private:
		std::string			_Target;
	protected:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm&);
		void		execute(Bureaucrat const & executor);
		
	class OpenShrubberyError: public std::exception
	{
		const char* what() const throw();
	};
};

#endif
