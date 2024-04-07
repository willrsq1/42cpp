#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _Name("No Name")
{
	CLASS("Constructor", "Bureaucrat");
	_Rank = UNDEFINED;
}

Bureaucrat::Bureaucrat(std::string name, int rank): _Name(name)
{
	CLASS("Constructor with inputs Name and Rank", "Bureaucrat");
	_Rank = rank;
	changeRank(rank);
}
Bureaucrat::~Bureaucrat()
{
	CLASS("Destructor", "Bureaucrat");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _Name(other._Name)
{
	CLASS("Constructor by copy", "Bureaucrat");
	*this = other;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	CLASS("Operand = Constructor", "Bureaucrat");
	if (this == &other)
		return (*this);
	_Rank = other._Rank;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_Name);
}

void Bureaucrat::incrGrade()
{
	changeRank(_Rank - 1);
}

void Bureaucrat::decrGrade()
{
	changeRank(_Rank + 1);
}

void Bureaucrat::changeRank(int new_rank)
{
	if (_Rank == UNDEFINED)
	{
		std::cerr << RED << "Bureaucrat " << this->_Name << "'s rank is undefined.";
		throw Bureaucrat::GradeUndefined();
	}
	if (new_rank < RANK_MAX)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his new grade: ";
		throw Bureaucrat::GradeTooHighException();
	}
	if (new_rank > RANK_MIN)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his new grade: ";
		throw Bureaucrat::GradeTooLowException();
	}
	_Rank = new_rank;
}

int Bureaucrat::getRank()
{
	return (_Rank);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& guy)
{
	out << "I am " << guy.getName() << ", my Bureaucrat grade is: ";
	if (guy.getRank() == UNDEFINED)
		out << "Undefined";
	else
		out << guy.getRank();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The new grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The new grade is too low.");
}

const char* Bureaucrat::GradeUndefined::what() const throw()
{
	return ("The grade needs to be defined at initialization.");
}