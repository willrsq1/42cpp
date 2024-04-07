#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

# define ERROR_EOF 1
# define RED	"\033[1;31m"
# define RESET_COLOR "\033[0m"
# define SIZEMAX_ALLOWED 10
# define INFORMATIONS_ARRAY_SIZE 5
# define NUMBER_OF_DISPLAYED_INFORMATIONS 3
# define FIRSTNAME 0
# define LASTNAME 1
# define NICKNAME 2
# define PHONE_NUMBER 3
# define DARKEST_SECRET 4
# define DISPLAY_WIDTH 40
class Contact
{
	private :
		std::string 	informations[INFORMATIONS_ARRAY_SIZE];
		std::string		show_name();
		std::string		show_lastname();
		std::string		show_nickname();
		std::string		show_phone();
		std::string		show_secret();
		int				new_information(std::string&, std::string);
		void			set_information(int, std::string);

	public :
						Contact();
		void			show_informations();
		int				new_contact();
		void			display();

};

#endif