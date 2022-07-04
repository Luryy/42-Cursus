#include <Account.hpp>
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {};
Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
};

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
};

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
};

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
};

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
};

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
};

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "deposit:" << deposit << ";";
		std::cout << "amount:" << (this->_amount + deposit ) << ";";
		std::cout << "nb_deposits:" << (this->_nbDeposits + 1) << std::endl;
		this->_amount += deposit;
		this->_nbDeposits++;
		this->_totalAmount += deposit;
		this->_totalNbDeposits++;
	}
};

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= this->_amount && withdrawal > 0)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		this->_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "withdrawal:refused" << std::endl;
	return false;
};

int		Account::checkAmount( void ) const
{
	return (this->_amount);
};

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};

void	Account::_displayTimestamp( void )
{
	time_t		timer_utc;
	struct tm	timer_local;

	timer_utc = time(NULL);
	localtime_r(&timer_utc, &timer_local);

	std::cout << "[";
	std::cout.fill('0');
	std::cout << timer_local.tm_year + 1900 <<
	std::setw(2) << timer_local.tm_mon + 1 <<
	std::setw(2) << timer_local.tm_mday <<
	'_' <<
	std::setw(2) << timer_local.tm_hour <<
	std::setw(2) << timer_local.tm_min <<
	std::setw(2) << timer_local.tm_sec;
	std::cout << "] ";
};
