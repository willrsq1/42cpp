#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	phonebook;
	std::string	input;

	std::cout << "\nWelcome to the PhoneBook Program !" << std::endl;
	std::cout << "Please enter one of three commands: ADD, SEARCH or EXIT.\n" << std::endl;
	while (1)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.new_contact();
		else if (input == "SEARCH")
			phonebook.show_contact();
		else if (input == "EXIT")
			return (EXIT_SUCCESS);
		else if (input.empty())
			std::cout << RED << "Error: input is empty. Try again." << RESET_COLOR << std::endl;
		else
			std::cout << RED << "Error: not a valid instruction." << RESET_COLOR << std::endl;
		if (std::cin.eof())
		{
			std::cout << RED << "\nError: EOF encountered. Exiting." << RESET_COLOR << std::endl;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}