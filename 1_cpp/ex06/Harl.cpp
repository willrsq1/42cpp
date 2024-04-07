#include "Harl.hpp"


Harl::Harl()
{
	funct_ptr[0] = &Harl::debug;
	funct_ptr[1] = &Harl::error;
	funct_ptr[2] = &Harl::info;
	funct_ptr[3] = &Harl::warning;
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructed" << std::endl;
}

void	Harl::complain(std::string s)
{
	if (s != "DEBUG" && s != "INFO" && s != "WARNING" && s != "ERROR")
	{
		std::cerr << s << ": Not a valid complain." << std::endl;
		return ;
	}
	(this->*funct_ptr[(int)((s[0] * s[1] - 2) % 5)])();
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG MESSAGE]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO MESSAGE]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING MESSAGE]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR MESSAGE]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}