#include <iostream>
#include <fstream>

bool	get_text(std::string& full_text, std::string filename)
{
	std::string		line;
	std::ifstream 	file(filename);

    if (!file.is_open())
	{
		std::cerr << "Error: " << filename << ": Impossible to open." << std::endl;
		return (1);
	}
	while (std::getline(file, line))
	{
		full_text += line;
		if (!file.eof())
			full_text += '\n';
	}
	file.close();
	return (0);
}

void	my_str_replace(std::string& full_text, std::string text_to_find, std::string text_to_replace)
{
	std::string		substr_1;
	std::string		substr_2;
	size_t			pos;
	size_t			prev_pos;

	prev_pos = 0;
	while (1)
	{
		pos = full_text.find(text_to_find, prev_pos);
		if (pos == std::string::npos)
			break ;
		substr_1 = full_text.substr(0, pos);
		substr_2 = full_text.substr(pos + text_to_find.size(), full_text.size());
		full_text = substr_1 + text_to_replace + substr_2;
		prev_pos = substr_1.size() + text_to_replace.size();
	}
}

bool	create_and_write_to_file(std::string& full_text, std::string filename)
{
	std::ofstream 	file(filename + ".replace");

	if (!file.is_open())
	{
		std::cerr << "Error: " << filename << ".replace" << ": Impossible to open." << std::endl;
		return (1);
	}
	file << full_text;
	file.close();
	return (0);
}

int main(int argc, char **argv)
{
	std::string		line;
	std::string		full_text;
	std::string		buffer;

	if (argc != 4)
	{
		std::cerr << "Bad inputs, has to be: ./my_program <filename> string1 string2" << std::endl;
		return (EXIT_FAILURE);
	}
	if (get_text(full_text, argv[1]))
		return (EXIT_FAILURE);
	if (argv[2][0])
		my_str_replace(full_text, argv[2], argv[3]);
	if (create_and_write_to_file(full_text, argv[1]))
		return (EXIT_FAILURE);
	return (0);
}
