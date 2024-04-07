#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string			_Name;
		bool						_Signed;
		const int					_signGrade;
		const int					_execGrade;
		Form();
	protected:

	public:
		Form(std::string, int, int);
		~Form();
		Form(const Form&);
		Form& operator= (const Form&);

		std::string				getName() const;
		bool					getSigned() const;
		int						getSignGrade() const;
		int						getExecGrade() const;

		void					beSigned(Bureaucrat&);
		
	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& 	operator<<(std::ostream&, const Form&);

#endif
