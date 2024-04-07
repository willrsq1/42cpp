#include "BitcoinExchange.hpp"


BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	CLASS("Constructor by copy", "BitcoinExchange");
	if (this == &other)
		return ;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
	CLASS("Operand = Constructor", "BitcoinExchange");
	this->database = other.database;
	return (*this);
}

bool    BitcoinExchange::datesAreOrdered(std::string const & date)
{
	int year = atoi(date.c_str());
	int month = atoi(date.c_str() + 5);
	int day = atoi(date.c_str() + 8);

	int previous_date = previous_year * 10000 + previous_month * 100 + previous_day;
	int new_date = year * 10000 + month * 100 + day;
	if (new_date < previous_date)
	{
		std::cerr << "The dates are not in ascending order." << std::endl;
		std::cerr << new_date << " and " << previous_date << std::endl;
		return false;
	}
	previous_year = year;
	previous_month = month;
	previous_day = day;
	return true;
}

BitcoinExchange::BitcoinExchange(): previous_day(0), previous_month(0), previous_year(0)
{
	try
	{
		std::ifstream filename("data.csv");

		if (!filename.is_open()) 
		{
			throw BitcoinExchange::BadOpen();
		}

		std::string line;
		std::string date;
		std::string value;

		std::getline(filename, line);

		if (line != "date,exchange_rate") // Skip the first line of the file
		{
			std::cerr << "The first line should be 'date,exchange_rate'." << std::endl;
			throw::BitcoinExchange::BadData();
		}

		while (std::getline(filename, line)) 
		{
			size_t pos = line.find(','); // If a comma is found, the date and value are extracted

			if (pos == std::string::npos) 
			{
				std::cerr << "No comma at line: '" << line << "': ";
				filename.close();
				throw::BitcoinExchange::BadData();
			}

			date = line.substr(0, pos);

			if (!isValidDate(date + " ") || !datesAreOrdered(date))
			{
				std::cerr << "At line: '" << line << "': ";
				filename.close();
				throw::BitcoinExchange::BadData();
			}

			value = line.substr(pos + 1);
			if (!isValidValueData(value))
			{
				std::cerr << "At line: '" << line << "': ";
				filename.close();
				throw::BitcoinExchange::BadData();
			}
			
			this->database[date] = strtod(value.c_str(), NULL); // Storing data in the database
		}

		filename.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}


void BitcoinExchange::execution(const std::string& inputFile) 
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open()) 
	{
		std::cerr << inputFile << " : couldn't be opened." << std::endl;
		return;
	}

	// Check the first line of the file
	std::string firstLine;
	if (!std::getline(file, firstLine)) 
	{
		std::cerr << "Error : the file is empty." << std::endl;
		return;
	}

	// Verify that the first line is 'date | value'
	if (firstLine != "date | value") 
	{
		std::cerr << "Error: The first line of the file must be 'date | value'." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) 
	{
		std::istringstream lineStream(line);
		std::string date, valueStr;

		if (!(std::getline(lineStream, date, '|') >> valueStr)) // Extract the string from <lineStream> up to the character <|>. The extracted string is stored in the variable <date>
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		size_t spaceCount = std::count(line.begin(), line.end(), ' ');
		if (spaceCount != 2)
		{
			std::cerr << "Error: Invalid number of spaces before or after the pipe." << std::endl;
			continue;
		}

		if (std::count(line.begin(), line.end(), '\t') != 0)
		{
			std::cerr << "Error: Tab ('\t') in input." << std::endl;
			continue;
		}

		
		displayResult(date, valueStr);
	}
}



void BitcoinExchange::displayResult(const std::string& date, const std::string& valueStr) const 
{

	try 
	{
		if (!isValidDate(date)) 
		{
			return;
		}

		// Convert the value of the string to a floating number
		float value = std::atof(valueStr.c_str());

		if (!isValidValue(valueStr)) 
		{
			return;
		}

		float result = 0.0;

		// Initialize the iterator at the beginning of the map
		std::map<std::string, float>::const_iterator it = this->database.begin();

		// Traverse the map until the correct date is found
		while (it != this->database.end() && it->first < date) 
		{
			++it;
		}

		// Handle the case where the requested date is earlier than the first date in the map
		if (it == this->database.begin()) 
		{
			std::cerr << "Bitcoin didn't exist as of " << date << std::endl;
			return;
		}

		// Decrement the iterator to go back to the previous date
		--it;

		// Calculate the value
		result = value * it->second;

		// Display the result
		std::cout << date << "=> " << value << " = " << result << std::endl;
	} 
	catch (const std::invalid_argument& e) 
	{
		std::cerr << "Error: Invalid value. Please enter a valid positive number." << std::endl;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 11) // The date must have a length of 10 characters (YYYY-MM-DD).
	{
		std::cerr << "Error: Invalid date format. Please use the format YYYY-MM-DD." << std::endl;
		return false;
	}


	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				std::cerr << "Error: Invalid date format. Please use the format YYYY-MM-DD." << std::endl;
				return false;
			}
		}
		else if (!isdigit(date[i]))
		{
			std::cerr << "Error: Invalid date format. Please use the format YYYY-MM-DD with valid digits." << std::endl;
			return false;
		}
	}

	int year = atoi(date.c_str());
	int month = atoi(date.c_str() + 5);
	int day = atoi(date.c_str() + 8);

	if (year > 2024)
	{
		std::cerr << "Error: The Bitcoin value is not available for dates after 2024." << std::endl;
		return false;
	}
	
	if (day == 0 || month == 0)
	{
		std::cerr << "Error: 00 isn't a valid day/month: " << date << "." << std::endl;
		return false;
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
	{
		std::cerr << "Error : April, June, September, and November have 30 days. " << std::endl;
		return false;
	}
	else if (month == 2) // Handle the month of February
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // Leap year
		{
			if (day > 29) 
			{
				std::cerr << "Error : February has 29 days in a leap year." << std::endl;
				return false;
			}
		} 
		else 
		{
			if (day > 28) 
			{
				std::cerr << "Error : February has 28 days." << std::endl;
				return false;
			}
		}
	} 
	else if (day > 31) // Check the number of days for the other months
	{
		std::cerr << "Error : This month has 31 days." << std::endl;
		return false;
	}
	return true;
}


bool BitcoinExchange::isValidValue(const std::string& valueStr) const
{
	bool    dot = false;

		for (size_t i = 0; i < valueStr.size(); i++)
		{
			if (isdigit(valueStr[i]) == false)
			{
				if (valueStr[i] == '.' && dot == false && valueStr[i + 1] != '\0' && i != 0)
				{
					dot = true;
					continue;
				}
				std::cerr << "Error: The value must be a positive number." << std::endl;
				return false;
			}
		}

		float value = std::atof(valueStr.c_str());
		if (value < 0.0 || value > 1000.0) 
		{
			std::cerr << "Error: The value must be a positive number between 0 and 1000." << std::endl;
			return false;
		}
		return true;
}

bool BitcoinExchange::isValidValueData(const std::string& valueStr) const
{
	bool    dot = false;

		for (size_t i = 0; i < valueStr.size(); i++)
		{
			if (isdigit(valueStr[i]) == false)
			{
				if (valueStr[i] == '.' && dot == false && valueStr[i + 1] != '\0' && i != 0)
				{
					dot = true;
					continue;
				}
				std::cerr << "Error: The value in data.csv must be a positive number." << std::endl;
				return false;
			}
		}

		float value = std::atof(valueStr.c_str());
		if (value < 0.0 || value > 1000000.0) 
		{
			std::cerr << "Error: The value in data.csv must be a positive number between 0 and 1000000." << std::endl;
			return false;
		}
		return true;
}


const char *BitcoinExchange::BadOpen::what() const throw()
{
	return ("File couldn't be opened");
}

const char *BitcoinExchange::BadData::what() const throw()
{
    return ("Data.csv file is improperly formatted.");
}
