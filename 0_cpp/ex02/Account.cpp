#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts += 1;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" <<_totalAmount << ";deposits:" <<_totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbDeposits << std::endl;
	return (true);
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}












void	Account::_displayTimestamp( void )
{
	std::time_t		currentTime = std::time(NULL);
	std::tm 		localTime = *std::localtime(&currentTime);

	int year = localTime.tm_year + 1900;
	int	month = localTime.tm_mon + 1;
	int	day = localTime.tm_mday;
	int	hour = localTime.tm_hour;
	int	minutes = localTime.tm_min;
	int	secs = localTime.tm_sec;
	std::cout << "[" << year;
	std::cout << std::setw(2) << std::setfill('0') << month;
	std::cout << std::setw(2) << std::setfill('0') << day << "_";
	std::cout << std::setw(2) << std::setfill('0') << hour;
	std::cout << std::setw(2) << std::setfill('0') << minutes;
	std::cout << std::setw(2) << std::setfill('0') << secs;
	std::cout << "] ";
}