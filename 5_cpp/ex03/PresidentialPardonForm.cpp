#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5)
{	
	CLASS("Constructor", "PresidentialPardonForm");
	this->_Target = "No defined targets";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Pardon Form", 25, 5)
{
	this->_Target = target;
	CLASS("Constructor", "PresidentialPardonForm with input target");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	CLASS("Destructor", "PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): Form("Presidential Pardon Form", 25, 5)
{
	CLASS("Constructor by copy", "PresidentialPardonForm");
	if (this == &other)
		return ;
	this->_Target = other._Target;
	this->setSigned(other.getSigned());
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& other)
{
	CLASS("Operand = Constructor", "PresidentialPardonForm");
	if (this == &other)
		return (*this);
	this->_Target = other._Target;
	this->setSigned(other.getSigned());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	this->checkPermissions(executor);
	std::cout << BLUE << this->_Target << " has been pardonned by Zaphod Beeblebox." << RESET_COLOR << std::endl;
}
