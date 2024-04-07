#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define RANK_MAX 1
# define RANK_MIN 150
# define UNDEFINED -42
# ifndef CLASS
#  define CLASS(x, y) std::cout << ""
// #  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif
# define RED	"\033[1;31m"

class Bureaucrat
{
	private:
		const std::string	_Name;
		int					_Rank;
		void				changeRank(int);
		Bureaucrat();
	protected:

	public:
		Bureaucrat(std::string, int);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator= (const Bureaucrat&);
		std::string		getName() const;
		void			incrGrade();
		void			decrGrade();
		int				getRank();

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeUndefined: public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& 	operator<<(std::ostream&, Bureaucrat&);

#endif
