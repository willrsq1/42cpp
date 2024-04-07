#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



void	make_the_exec_a_noob(Bureaucrat executor)
{
	while (executor.getRank() < 150)
		executor.decrGrade();
}

void	get_a_form_signed(Form *form, Bureaucrat executor)
{
	while (executor.getRank() > form->getSignGrade())
		executor.incrGrade();
	form->beSigned(executor);
	while (executor.getRank() > form->getExecGrade())
		executor.incrGrade();
	executor.executeForm(*form);
	form->execute(executor);
}

int	main()
{
	try
	{
		PresidentialPardonForm a("Bob");
		RobotomyRequestForm b("Eya");
		ShrubberyCreationForm c = ShrubberyCreationForm("Jack");

		Bureaucrat		guy("Paul", 150);
		get_a_form_signed(&a, guy);
		make_the_exec_a_noob(guy);
		get_a_form_signed(&b, guy);
		make_the_exec_a_noob(guy);
		get_a_form_signed(&c, guy);

		PresidentialPardonForm d("Emma");

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		guy.executeForm(d);
		while (guy.getRank() > d.getSignGrade())
			guy.incrGrade();
		d.beSigned(guy);
		
		guy.executeForm(d);
		d.execute(guy);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET_COLOR << '\n';
		return (1);
	}
	return (0);
}