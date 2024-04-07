#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char **argv)
{
	std::list<std::string>		args = split(argv[1], ' ');

	if (args.empty())
		throw RPN::Empty();
	ListInit(args);
	if (this->_Numbers.size() != 1)
		throw RPN::MissingOperators();
	std::cout << "Result is: " << *(this->_Numbers.begin()) << std::endl;
}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
	CLASS("Constructor by copy", "RPN");
	if (this == &other)
		return ;
	this->_Numbers = other._Numbers;
}

RPN& RPN::operator= (const RPN& other)
{
	CLASS("Operand = Constructor", "RPN");
	if (this == &other)
		return (*this);
	this->_Numbers = other._Numbers;
	return (*this);
}

void RPN::_FtCalcul(std::string s)
{
	long long	number;
	long long	stl;

	if (this->_Numbers.size() == 1)
		throw RPN::InputNotFormatedWell();
	number = this->_Numbers.back();
	this->_Numbers.pop_back();
	stl = this->_Numbers.back();
	if (s == "+")
		stl += number;
	else if (s == "-")
		stl -= number;
	else if (s == "*")
		stl *= number;
	else if (s == "/")
	{
		if (number == 0)
			throw RPN::DivisionByZero();
		stl /= number;
	}
	if (stl > INT_MAX || stl < INT_MIN)
	{
		std::cout << this->_Numbers.back() << " " << s << " " << number << " = " << stl << ": ";
		throw RPN::OutOfRange();
	}
	this->_Numbers.pop_back();
	this->_Numbers.push_back(stl);
}

void RPN::ListInit(std::list<std::string> lst)
{
	std::string	s;
	std::list<std::string>::iterator		it = lst.begin();
	std::list<std::string>::iterator		ite = lst.end();

	while (it != ite)
	{
		try
		{
			this->_Numbers.push_back(my_atoi((*it).c_str()));
		}
		catch (...)
		{
			if (!is_operator(*it))
				throw RPN::BadOp();
			_FtCalcul(*it);
		}
		it++;
	}
}


bool	RPN::is_operator(std::string s)
{
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return (1);
	return (0);
}


int	RPN::my_atoi(const char *s)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw RPN::Empty();
	while (s[i] && s[i] == '0')
		i++;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		result = result * 10 + (s[i] - 48);
		if (result > 9)
			throw RPN::BadArg();
		i++;
	}
	if (s[i] || result > INT_MAX)
	{
		throw RPN::BadArg();
	}
	return (result);
}

std::list<std::string> RPN::split(const std::string &str, char delimiter) 
{
    std::list<std::string> result;
    std::string token;
    
    for (size_t i = 0; i < str.length(); ++i)
	{
        if (str[i] != delimiter)
		{
            token += str[i];
        }
		else 
		{
            if (!token.empty())
			{
                result.push_back(token);
                token.clear();
            }
        }
    }
    if (!token.empty())
	{
        result.push_back(token);
    }
    return result;
}

const char * RPN::BadArg::what() const throw()
{
	return ("bad arg: should be between 0 and 9");
}
const char * RPN::BadOp::what() const throw()
{
	return ("The input in improperly formated, only numbers (positive ints) from 0 to 9 and operands are allowed");
}
const char * RPN::Empty::what() const throw()
{
	return ("empty arg");
}
const char * RPN::InputNotFormatedWell::what() const throw()
{
	return ("The input is missing numbers");
}
const char * RPN::MissingOperators::what() const throw()
{
	return ("The input is missing operators, too many numbers in stack at the end");
}
const char * RPN::OutOfRange::what() const throw()
{
	return ("The result is out of range (not an int)");
}
const char * RPN::DivisionByZero::what() const throw()
{
	return ("Unallowed divsion by zero");
}