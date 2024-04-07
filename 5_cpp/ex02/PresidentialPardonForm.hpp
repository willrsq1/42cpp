#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class PresidentialPardonForm: public Form
{
	private:
		std::string			_Target;
	protected:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator= (const PresidentialPardonForm&);
		void		execute(Bureaucrat const & executor);
};

#endif
