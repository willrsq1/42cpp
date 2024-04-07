#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <sstream>

# define PHONEBOOK_SIZE 8
# define ERROR_EOF 1
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET_COLOR "\033[0m"

class PhoneBook
{
	int		contact_index;
	int		number_of_registered_contacts;
	Contact	Contacts[PHONEBOOK_SIZE];

	public :
				PhoneBook();
		void	new_contact();
		void	show_contact();
};

#endif