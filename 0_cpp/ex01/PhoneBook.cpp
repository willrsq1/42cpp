#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_index = 0;
	number_of_registered_contacts = 0;
}

void	PhoneBook::new_contact()
{
	if (Contacts[contact_index].new_contact())
		return ;
	std::cout << GREEN << "\nSuccess: a new contact, number " << contact_index << ", has been added !\n" << RESET_COLOR << std::endl;
	contact_index += 1;
	if (number_of_registered_contacts < PHONEBOOK_SIZE)
		number_of_registered_contacts += 1;
	if (contact_index == PHONEBOOK_SIZE)
		contact_index = 0;
}

void	PhoneBook::show_contact()
{
	std::string		input;
	int				number;

	number = 0;
	if (number_of_registered_contacts == 0)
	{
		std::cout << RED << "Error: No contact has been registered yet. Please add some contacts before trying again." << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << GREEN << "\nDisplay of the registered contacts:\n" << RESET_COLOR << std::endl;
	while (number < number_of_registered_contacts)
	{
		std::cout << "         " << number << "|"; 
		Contacts[number].display();
		number++;
	}
	std::cout << std::endl;
	while (1)
	{
		std::cout << "Enter the number of the contact you want to see: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		std::istringstream	iss(input);
		if (iss >> number && input.length() == 1 && std::isdigit((int)input[0]))
		{
			if (number >= 0 && number < number_of_registered_contacts)
				break ;
			else if (number_of_registered_contacts == 1)
				std::cout << RED << "Error: The number must be 0 (only one contact was added). Thank you !" << RESET_COLOR << std::endl;
			else
				std::cout << RED << "Error: Not a an existing contact. Please enter a number between 0 and " \
					<< number_of_registered_contacts - 1 << ". Thank you !" << RESET_COLOR << std::endl;
		}
		else if (number < 0 || number >= PHONEBOOK_SIZE)
			std::cout << RED << "Error: The number must be in the range 0 - 7. Thank you !" << RESET_COLOR << std::endl;
		else
			std::cout << RED << "Error: Not a valid number. Try again please." << RESET_COLOR << std::endl;
	}
	std::cout << GREEN << "\nSuccess: Displaying contact number " << number << ". Thank you !" << RESET_COLOR << std::endl;
	Contacts[number].show_informations();
}