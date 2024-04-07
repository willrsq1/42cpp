#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	CLASS("Constructor", "ScalarConverter");
}

ScalarConverter::~ScalarConverter()
{
	CLASS("Destructor", "ScalarConverter");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	CLASS("Constructor by copy", "ScalarConverter");
	if (this == &other)
		return ;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other)
{
	CLASS("Operand = Constructor", "ScalarConverter");
	if (this == &other)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		ERR("Input can't be empty");
		return ;
	}
	if (input == "nanf" || input == "nan")
	{
		CHAR("Impossible");
		INT("Impossible");
		FLOAT("nan", "f");
		DOUBLE("nan", "");
	}
	else if (input == "+inf" || input == "+inff")
	{
		CHAR("Impossible");
		INT("Impossible");
		FLOAT("+inf", "f");
		DOUBLE("+inf", "");
	}
	else if (input == "-inf" || input == "-inff")
	{
		CHAR("Impossible");
		INT("Impossible");
		FLOAT("-inf", "f");
		DOUBLE("-inf", "");
	}
	else if (ScalarConverter::isFloat(input))
		ScalarConverter::typeFloat(input);
	else if (ScalarConverter::isDouble(input))
		ScalarConverter::typeDouble(input);
	else if (ScalarConverter::isInt(input))
		ScalarConverter::typeInt(input);
	else if (ScalarConverter::isChar(input))
		ScalarConverter::typeChar(input);
	else
		ERR("Not a valid decimal representation of neither char, int, double, nor float.");
}

bool ScalarConverter::isFloat(const std::string & input)
{
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos || pos == input.length() - 1)
		return (0);
	if (!(input.length() >= 2 && input[input.length() - 1] == 'f' && input[input.length() - 2] != '.'))
			return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]) && \
			!(input[i] == '.' && i == pos) && \
			!(input[i] == 'f' && i == input.length() - 1))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isDouble(const std::string & input)
{
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos || pos == input.length() - 1)
		return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]) && \
			!(input[i] == '.' && i == pos))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isInt(const std::string & input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isChar(const std::string & input)
{
	if (std::isprint(input[0]) && input.length() == 1)
		return (1);
	return (0);
}

void ScalarConverter::typeChar(const std::string & input)
{
	std::istringstream	iss(input);
	char		c;

	if (!(iss >> c))
	{
		CHAR("Non Displayable");
		int	a;
		iss >> a;
		INT(a);
		FLOAT(a, ".0f");
		DOUBLE(a, ".0");
		ERR("Char Overflowed");
		return ;
	}
	CHAR(c);
	INT(static_cast<int>(c));
	FLOAT(static_cast<float>(c), ".0f");
	DOUBLE(static_cast<double>(c), ".0");
}

void ScalarConverter::typeInt(const std::string & input)
{
	std::istringstream	iss(input);
	int			i;

	if (!(iss >> i))
	{
		CHAR("Int Overflowed");
		INT("Overflowed");
		FLOAT("Int Overflowed", "");
		DOUBLE("Int Overflowed", "");
		ERR("Int overflowed !");
		return ;
	}
	
	if (i >= 32 && i < 127)
		CHAR(static_cast<char>(i));
	else
		CHAR("Non Displayable");
	INT(i);
	FLOAT(i, ".0f");
	DOUBLE(i, ".0");
	
}

void ScalarConverter::typeFloat(const std::string & input)
{
	std::istringstream	iss(input);
	float		f;

	if (!(iss >> f))
	{
		CHAR("Error");
		INT("Error");
		FLOAT("Error", ": Overflow");
		DOUBLE("Error", "");
		ERR("Float Overflowed");
		return ;
	}
	if (f >= 32 && f < 127)
		CHAR(static_cast<char>(f));
	else
		CHAR("Non Displayable");
	if (f >= INT_MIN && (int)f <= INT_MAX)
		INT(static_cast<int>(f));
	else
		INT("Overflow");
	FLOAT((f), ((static_cast<float>(static_cast<int>(f)) == static_cast<float>(f)) ? ".0f": "f"));
	DOUBLE(static_cast<double>(f), ((static_cast<double>(static_cast<int>(f)) == static_cast<double>(f)) ? ".0": ""));
	
}

void ScalarConverter::typeDouble(const std::string & input)
{
	std::istringstream	iss(input);
	double		d;

	if (!(iss >> d))
	{
		CHAR("Error");
		INT("Error");
		FLOAT("Error", "");
		DOUBLE("Error", ": Overflow");
		ERR("Double Overflowed");
		return ;
	}
	if (d >= 32 && d < 127)
		CHAR(static_cast<char>(d));
	else
		CHAR("Non Displayable");
	if (d >= INT_MIN && d <= INT_MAX)
		INT(static_cast<int>(d));
	else
		INT("Overflow");
	FLOAT(static_cast<float>(d), ((static_cast<float>(static_cast<int>(d)) == static_cast<float>(d)) ? ".0f": "f"));
	DOUBLE(d, ((static_cast<double>(static_cast<int>(d)) == static_cast<double>(d)) ? ".0": ""));
}
