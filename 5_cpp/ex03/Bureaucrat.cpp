#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _Name("No Name")
{
	CLASS("Constructor", "Bureaucrat");
	this->_Rank = UNDEFINED;
}

Bureaucrat::Bureaucrat(std::string name, int rank): _Name(name)
{
	CLASS("Constructor with inputs Name and Rank", "Bureaucrat");
	this->_Rank = UNDEFINED;
	changeRank(rank);
}
Bureaucrat::~Bureaucrat()
{
	CLASS("Destructor", "Bureaucrat");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _Name(other._Name)
{
	CLASS("Constructor by copy", "Bureaucrat");
	if (this == &other)
		return ;
	this->_Rank = other._Rank;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	CLASS("Operand = Constructor", "Bureaucrat");
	if (this == &other)
		return (*this);
	this->_Rank = other._Rank;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_Name);
}

void Bureaucrat::incrGrade()
{
	this->changeRank(this->_Rank - 1);
}

void Bureaucrat::decrGrade()
{
	this->changeRank(this->_Rank + 1);
}

void Bureaucrat::changeRank(int new_rank)
{
	if (new_rank < RANK_MAX)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his grade: " << RESET_COLOR;
		throw Bureaucrat::GradeTooHighException();
	}
	if (new_rank > RANK_MIN)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his grade: " << RESET_COLOR;
		throw Bureaucrat::GradeTooLowException();
	}
	this->_Rank = new_rank;
}

int Bureaucrat::getRank() const
{
	return (this->_Rank);
}

bool Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
	{
		std::cout << RED << "Bureaucrat [" << this->_Name << "] couldn't sign the form [" << form.getName() << \
			"] because it is already signed." << RESET_COLOR << std::endl;
		return (1);
	}
	if (this->_Rank > form.getSignGrade())
	{
		std::cout << RED << "Bureaucrat [" << this->_Name << "] couldn't sign the form [" << form.getName() \
			<< "] because the Bureaucrat doesn't have a high enough grade." << RESET_COLOR << std::endl;
		return (1);
	}
	std::cout << GREEN << "Bureaucrat [" << this->_Name << "] has signed the form [" << form.getName() << "] ";
	std::cout << "(Bureaucrat's grade = " << this->_Rank << ", form's grade = " << form.getSignGrade() << ")." << RESET_COLOR << std::endl;
	return (0);
}

void Bureaucrat::executeForm(Form const & form) const
{
	if (form.getSigned() == 0)
		std::cout << RED << "The form [" << form.getName() << "] has not been signed yet." << RESET_COLOR << std::endl;
	else if (this->_Rank > form.getExecGrade())
	{
		std::cout << RED << "The form [" << form.getName() << "] cannot be executed by [";
		std::cout << this->_Name << "], because it's grade is [" << this->_Rank;
		std::cout << "], lower than [" << form.getExecGrade() << "]." << RESET_COLOR << std::endl;
	}
	else
		std::cout << GREEN << "Bureaucrat [" << this->_Name << "] executed Form [" << form.getName() << "]." << RESET_COLOR << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& guy)
{
	out << "The Bureaucrat [" << guy.getName() << "]'s grade is ";
	if (guy.getRank() == UNDEFINED)
		out << "Undefined";
	else
		out << guy.getRank();
	out << ".";
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: the new grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: the new grade is too low.");
}