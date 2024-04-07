# include "Contact.hpp"

Contact::Contact()
{
	informations[FIRSTNAME] = "Firstname";
	informations[LASTNAME] = "Lasttname";
	informations[NICKNAME] = "Nickname";
	informations[PHONE_NUMBER] = "Phone number";
	informations[DARKEST_SECRET] = "Darkest secret";
}

std::string	Contact::show_name()
{
	return (informations[FIRSTNAME]);
}

std::string	Contact::show_lastname()
{
	return (informations[LASTNAME]);
}

std::string	Contact::show_nickname()
{
	return (informations[NICKNAME]);
}

std::string	Contact::show_phone()
{
	return (informations[PHONE_NUMBER]);
}

std::string	Contact::show_secret()
{
	return (informations[DARKEST_SECRET]);
}

void	Contact::show_informations()
{
	std::cout << std::endl;
	std::cout << std::setw(DISPLAY_WIDTH) << std::left << "This contact's first name is: "     << std::setw(0) << show_name()     << std::endl;
	std::cout << std::setw(DISPLAY_WIDTH) << std::left << "This contact's last name is: "      << std::setw(0) << show_lastname() << std::endl;
	std::cout << std::setw(DISPLAY_WIDTH) << std::left << "This contact's nickname is: "       << std::setw(0) << show_nickname() << std::endl;
	std::cout << std::setw(DISPLAY_WIDTH) << std::left << "This contact's phone number is: "   << std::setw(0) << show_phone()    << std::endl;
	std::cout << std::setw(DISPLAY_WIDTH) << std::left << "This contact's darkest secret is: " << std::setw(0) << show_secret()   << std::endl;
	std::cout << std::endl;
}

int	Contact::new_contact()
{
	std::string		input;
	std::string		info_types[] = {"Name", "Last Name", "NickName", "Phone Number", "Darkest Secret"};
	int				i;

	i = 0;
	while (i < INFORMATIONS_ARRAY_SIZE)
	{
		if (new_information(input, info_types[i]))
			return (ERROR_EOF);
		set_information(i, input);
		i++;
	}
	return (0);
}

int	Contact::new_information(std::string& input, std::string information)
{
	while (1)
	{
		std::cout << "Please enter the contact's " << information << " : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (ERROR_EOF);
		if (input.empty())
			std::cout << RED << "Input cannot be empty. Try again." << RESET_COLOR << std::endl;
		else
			return (0);
	}
}

void	Contact::set_information(int i, std::string information)
{
	informations[i] = information;
}

void	Contact::display()
{
	int				i;
	std::string		information;

	i = 0;
	while (i < NUMBER_OF_DISPLAYED_INFORMATIONS)
	{
		information = informations[i];
		if (information.size() > SIZEMAX_ALLOWED)
		{
			information = information.substr(0, 9);
			information = information.append(".");
		}
		std::cout << std::setw(SIZEMAX_ALLOWED) << std::right << information;
		if (i == NUMBER_OF_DISPLAYED_INFORMATIONS - 1)
			std::cout << std::endl;
		else
			std::cout << "|";
		i++;
	}
}