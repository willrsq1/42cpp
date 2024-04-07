#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please follow the requested format: ./RPN [arg]" << std::endl;
		return (1);
	}
	try 
	{
		RPN bob(argv);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
