/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Account.cpp                                       ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/13 16:58:14 by maroy                                    */
/*   Updated: 2023/10/26 18:23:39 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_totalAmount += this->checkAmount();
	this->_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "created" << endl;
}
Account::~Account()
{
	this->_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "closed" << endl;
	this->_nbAccounts--;
	this->_totalAmount -= this->checkAmount();
}

//////////////////////////////////////////
//										//
//			GETTERS						//
//										//
//////////////////////////////////////////

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

//////////////////////////////////////////
//										//
//			Make/Check					//
//										//
//////////////////////////////////////////

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << Account::checkAmount() << ";";
	if (deposit < 0)
		cout << "deposit:refused" << endl;
	else
	{
		cout << "deposit:" << deposit << ";";
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		cout << "amount:" << Account::checkAmount() << ";"
				<< "nb_deposits:" << this->_nbDeposits << endl;
	}
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << Account::checkAmount() << ";";
	if (withdrawal < 0 || withdrawal - Account::checkAmount() > 0)
	{
		cout << "withdrawal:refused" << endl;
		return (false);
	}
	else
	{
		cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		cout << "amount:" << Account::checkAmount() << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals << endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (Account::_amount);
}

//////////////////////////////////////////
//										//
//			Display						//
//										//
//////////////////////////////////////////

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals << endl;
}

void Account::_displayTimestamp(void)
{
	cout << "[19920104_091532] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << endl;
}