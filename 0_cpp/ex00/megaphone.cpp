#include <iostream>
#include <string>

int	main(int argc, char **argv){
	if (argc == 1){std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;return (0);	}
	while (*(++argv))
	{while ((**argv))
		std::cout << (char)std::toupper((*(*argv)++));}
	std::cout << std::endl;	return (0);}