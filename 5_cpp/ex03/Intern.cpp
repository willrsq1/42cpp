#include "Intern.hpp"

Intern::Intern()
{
	_Tab[0] = PRESI;
	_Tab[1] = ROBO;
	_Tab[2] = SHRUB;
	CLASS("Constructor", "Intern");
}

Intern::~Intern()
{
	CLASS("Destructor", "Intern");
}

Intern::Intern(const Intern& other)
{
	CLASS("Constructor by copy", "Intern");
	if (this == &other)
		return ;
	_Tab[0] = PRESI;
	_Tab[1] = ROBO;
	_Tab[2] = SHRUB;
}

Intern& Intern::operator= (const Intern& other)
{
	CLASS("Operand = Constructor", "Intern");
	if (this == &other)
		return (*this);
	_Tab[0] = PRESI;
	_Tab[1] = ROBO;
	_Tab[2] = SHRUB;
	return (*this);
}

Form* Intern::makeForm(std::string type, std::string target)
{
	int	i;

	i = 0;
	while (i < INTERN_TAB_SIZE && type != this->_Tab[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << GREEN << "Intern creates " << PRESI << RESET_COLOR << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << GREEN << "Intern creates " << ROBO << RESET_COLOR << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << GREEN << "Intern creates " << SHRUB << RESET_COLOR << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cerr << RED << "error: the form [" << target << "]doesn't exist." << RESET_COLOR << std::endl;
			break;
	}
	return (NULL);
}
