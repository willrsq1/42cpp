#include <iostream>

int	main()
{
	const std::string	str = "HI THIS IS BRAIN";
	const std::string	*stringPTR = &str;
	const std::string	&stringREF = str;

	std::cout << "Part 1:" << std::endl;
	std::cout << "str address: " << &str << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;

	std::cout << "Part 2:" << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "stringPTR pointed value: " << *stringPTR << std::endl;
	std::cout << "stringREF referenced value: " << stringREF << std::endl;

	std::cout << "THE END." << std::endl;
	return (0);
}