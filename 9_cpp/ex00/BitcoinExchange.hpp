#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <map>
# include <string>

# ifndef CLASS
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;

        int     previous_day;
        int     previous_month;
        int     previous_year;

        bool datesAreOrdered(std::string const & date);
        void displayResult(const std::string& date, const std::string& valueStr) const;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr) const;
        bool isValidValueData(const std::string& valueStr) const;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator= (const BitcoinExchange&);


        void execution(const std::string& inputFile);

        class BadOpen : public std::exception
        {
            const char *what() const throw();
        };
        
        class BadData : public std::exception
        {
            const char *what() const throw();
        };
};

#endif
