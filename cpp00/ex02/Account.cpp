/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:38 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 17:15:44 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#define BLUE "\033[1;34m"
#define WHITE "\033[1;30m"

int  Account::_nbAccounts = 0;
int  Account::_totalAmount = 0;
int  Account::_totalNbDeposits = 0;
int  Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){
	return(_nbAccounts);
}

int Account::getTotalAmount( void ){
	return(_totalAmount);
}

int Account::getNbDeposits( void ){
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
	return(_totalNbWithdrawals);
}

void Account::_displayTimestamp( void ) {
    time_t t = time(NULL);
	struct tm *pLocal = localtime(&t);
	std::cout << WHITE << '[' << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal->tm_mday <<
		'_' << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";
}

Account::Account( int initial_deposite ) :
				_accountIndex(_nbAccounts),
				_amount(initial_deposite),
				_nbDeposits(0), _nbWithdrawals(0) 
{
	_nbAccounts++;
	_totalAmount += initial_deposite;
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE << ";amount:" << 
		BLUE << _amount << WHITE << ";created" << std::endl;
	
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << _nbAccounts << WHITE << ";total:" <<
		BLUE << _totalAmount << WHITE << ";deposits:" << BLUE << _totalNbDeposits << WHITE <<
		";withdrawls:" << BLUE << _totalNbWithdrawals << WHITE << std::endl;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE << ";amount:" << BLUE << _amount << 
		WHITE << ";deposits:" << BLUE << _nbDeposits << WHITE << ";withdrawls:" << BLUE << 
		_nbWithdrawals << WHITE << std::endl;
}

void Account::makeDeposit ( int deposit ) {
	int last_amount = _amount;
	_displayTimestamp();
	this-> _amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	std::cout << "index:" << BLUE << _accountIndex << WHITE << ";p_amount:" << BLUE << 
		last_amount << WHITE << ";deposit:" << BLUE << deposit << WHITE<< ";amount:" << 
		BLUE << _amount << WHITE << ";nb_deposits:" << BLUE << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal ( int withdrawal ) {
	int	last_amount = _amount;
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << BLUE << _accountIndex << WHITE  << ";p_amount:" << 
			BLUE << _amount << WHITE << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "index:" << BLUE << _accountIndex << WHITE  << ";p_amount:" << 
		BLUE << last_amount << WHITE  << ";withdrawal:" << BLUE << withdrawal << 
		WHITE << ";amount:" << BLUE << _amount << WHITE << ";nb_withdrwals:" << 
		BLUE << _nbWithdrawals << WHITE<< std::endl;
	return (true);
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << WHITE << ";amount:" << BLUE << _amount << 
		WHITE << ";closed" << std::endl;
}