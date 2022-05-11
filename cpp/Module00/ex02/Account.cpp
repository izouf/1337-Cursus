#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
        << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = time(0);
    struct tm   *tstruct = localtime(&now);
    char        buf[18];
   // tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", tstruct);
	std::cout << buf;
	return ;
}

Account::Account(int initial_deposit)
{
	
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	_totalNbWithdrawals += this->_nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

void    Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_totalNbDeposits += this->_nbDeposits;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" 
		<< this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount < withdrawal){
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (0);
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals += this->_nbWithdrawals;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (1);	
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << std::endl;
	return ;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

Account::Account(void){}