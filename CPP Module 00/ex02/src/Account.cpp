/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Account.cpp                                       ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/13 16:58:14 by maroy                                    */
/*   Updated: 2023/10/14 16:39:58 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <iostream>


// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit): _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_totalAmount += Account::checkAmount();
	
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << Account::checkAmount() << ";"
				<< "created" 
				<< std::endl;
}
Account::~Account(){
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << Account::checkAmount() << ";"
				<< "closed" 
				<< std::endl;
	
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::checkAmount();
}

int	Account::getNbAccounts( void ){
 	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << Account::checkAmount() << ";";
	if (deposit < 0) {
		std::cout << "deposit:refused" << std::endl;
	} else {
		std::cout << "deposit:" << deposit << ";";
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		std::cout	<< "amount:" << Account::checkAmount() << ";"
					<< "nb_deposits:" << this->_nbDeposits
					<< std::endl;
	}
}

bool Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << Account::checkAmount() << ";";
	if (withdrawal < 0 || withdrawal - Account::checkAmount() > 0){
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	} else {
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout	<< "amount:" << Account::checkAmount() << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
}

int Account::checkAmount( void ) const{
	return (Account::_amount);
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
 				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp( void ){
	std::cout << "[19920104_091532] ";
}

void Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
			   	<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
			 	<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}
