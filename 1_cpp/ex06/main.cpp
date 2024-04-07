#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl			man;
	int				case_id;
	std::string		arg;

	if (argc != 2)
	{
		std::cerr << "Error: use program like this: \"./harlFilter [arg]\"" << std::endl;
		std::cerr << "Options: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (EXIT_FAILURE);
	}
	arg = argv[1];
	if (arg == "DEBUG")
		case_id = 1;
	if (arg == "INFO")
		case_id = 2;
	if (arg == "WARNING")
		case_id = 3;
	if (arg == "ERROR")
		case_id = 4;
	switch (case_id)
	{
		case 1:
			man.complain("DEBUG");
			man.complain("INFO");
			man.complain("WARNING");
			man.complain("ERROR");
			break ;
		case 2:
			man.complain("INFO");
			man.complain("WARNING");
			man.complain("ERROR");
			break ;
		case 3:
			man.complain("WARNING");
			man.complain("ERROR");
			break ;
		case 4:
			man.complain("ERROR");
			break ;
		default:
			std::cerr << "Blablabla " << argv[1] << " blablabla" << std::endl;
			std::cerr << "Options: DEBUG, INFO, WARNING, ERROR" << std::endl;
			return (EXIT_FAILURE);
	}
	// switch (case_id)
	// {
	// 	case 1:
	// 		man.complain("DEBUG");
	// 	case 2:
	// 		man.complain("INFO");
	// 	case 3:
	// 		man.complain("WARNING");
	// 	case 4:
	// 		man.complain("ERROR");
	// 		break ;
	// 	default:
	// 		std::cerr << "Blablabla " << argv[1] << " blablabla" << std::endl;
	// 		std::cerr << "Options: DEBUG, INFO, WARNING, ERROR" << std::endl;
	// 		return (EXIT_FAILURE);
	// }
	return (EXIT_SUCCESS);
}