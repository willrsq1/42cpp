#include "Form.hpp"

Form::Form(): _Name("Undefined"), _Signed(0), _signGrade(UNDEFINED), _execGrade(UNDEFINED)
{
	CLASS("Constructor", "Form");
}

Form::Form(std::string name, int sign_grade, int exec_grade): _Name(name), _signGrade(sign_grade), _execGrade(exec_grade)
{
	CLASS("Constructor with input name, signgrade, execgrade", "Form");
	this->_Signed = 0;
	if (this->_signGrade < RANK_MAX)
	{
		std::cerr << RED << "For Form [" << this->_Name << "], with [" << this->_signGrade << "] as his new sign grade: ";
		throw Form::GradeTooHighException();
	}
	if (this->_execGrade < RANK_MAX)
	{
		std::cerr << RED << "For Form [" << this->_Name << "], with [" << this->_execGrade << "] as his new exec grade: ";
		throw Form::GradeTooHighException();
	}
	if (this->_signGrade > RANK_MIN)
	{
		std::cerr << RED << "For Form [" << this->_Name << "], with [" << this->_signGrade << "] as his new sign grade: ";
		throw Form::GradeTooLowException();
	}
	if (this->_execGrade > RANK_MIN)
	{
		std::cerr << RED << "For Form [" << this->_Name << "], with [" << this->_execGrade << "] as his new exec grade: ";
		throw Form::GradeTooLowException();
	}
}

void Form::checkPermissions(const Bureaucrat& guy)
{
	if (this->_Signed == 0)
		throw Form::NotSigned();
	if (guy.getRank() > this->_execGrade)
		throw Form::ExecutorNotGradedEnough();
}

void Form::setSigned(bool i)
{
	this->_Signed = i;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: the grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: the grade is too low.");
}

const char* Form::NotSigned::what() const throw()
{
	return ("This form is not signed: it can't be executed.");
}

const char* Form::ExecutorNotGradedEnough::what() const throw()
{
	return ("The executor isn't high graded enough to execute this form.");
}

Form::~Form()
{
	CLASS("Destructor", "Form");
}

Form::Form(const Form& other): _Name(other._Name), _Signed(other._Signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	CLASS("Constructor by copy", "Form");
	if (this == &other)
		return ;
}

Form& Form::operator= (const Form& other)
{
	CLASS("Operand = Constructor", "Form");
	if (this == &other)
		return (*this);
	this->_Signed = other._Signed;
	return (*this);
}

std::string Form::getName() const
{
	return (this->_Name);
}

bool Form::getSigned() const
{
	return (this->_Signed);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat& guy)
{
	if (guy.signForm(*this))
	{ 
		if (this->_Signed == 0)	
			throw Form::GradeTooLowException();
		return ;
	}
	this->_Signed = 1;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "The form [" << form.getName() << "] needs the grade [" << form.getSignGrade() << "] to be signed ";
	out << "and the grade [" << form.getExecGrade() << "] to be executed.";
	if (form.getSigned())
		out << " It is already signed.";
	else
		out << " It is not signed yet.";
	return (out);
}
