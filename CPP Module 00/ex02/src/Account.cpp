/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Account.cpp                                       ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/13 16:58:14 by maroy                                    */
/*   Updated: 2023/10/13 19:47:36 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <iostream>


// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += Account::checkAmount();
	Account::_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << Account::checkAmount() << ";created" << std::endl;
}
Account::~Account(){}

int	Account::getNbAccounts( void ){
 	return (_nbAccounts);
}

int Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit ){
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount << ";deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
	if (withdrawal > _amount)
		return (false);
	return (true);
}

int Account::checkAmount( void ) const{
	return (_amount);
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
 				<< "withdrawals:" << this->_nbWithdrawals << ";"
				<< std::endl;
}

void Account::_displayTimestamp( void ){
	std::cout << "[19920104_091532] ";
}

void Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
			   	<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
			 	<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}
