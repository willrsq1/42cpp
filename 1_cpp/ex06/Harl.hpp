#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>



class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void 	(Harl::*funct_ptr[4])(void);
	public:
		Harl(/* args */);
		~Harl();
		void	complain(std::string);
};

#endif