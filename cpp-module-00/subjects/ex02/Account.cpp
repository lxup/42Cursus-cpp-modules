/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:30:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/13 19:26:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


// ************************************************************************** //
//                                  PRIVATE                                   //
// ************************************************************************** //

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	std::time_t	t = std::time(0);

	std::cout	<< std::setfill('0') <<"[" << 1900 + std::localtime(&t)->tm_year
				<< std::setw(2) << 1 + std::localtime(&t)->tm_mon
				<< std::setw(2) << std::localtime(&t)->tm_mday
				<< "_"
				<< std::setw(2) << std::localtime(&t)->tm_hour
				<< std::setw(2) << std::localtime(&t)->tm_min
				<< std::setw(2) << std::localtime(&t)->tm_sec
				<< "] " << std::flush;
}

// ************************************************************************** //
//                                   PUBLIC                                   //
// ************************************************************************** //

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts << ";"
				<< "total:" << Account::_totalAmount << ";"
				<< "deposits:" << Account::_totalNbDeposits << ";"
				<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	++Account::_nbAccounts;
	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = initial_deposit;
	Account::_totalAmount += Account::_amount;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "amount:" << Account::_amount << ";"
				<< "created" << std::endl;
}

Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::_amount;
	this->_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "amount:" << Account::_amount << ";"
				<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "p_amount:" << Account::_amount << ";";
	Account::_amount += deposit;
	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << Account::_amount << ";"
				<< "nb_deposit:" << Account::_nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "p_amount:" << Account::_amount << ";"
				<< "withdrawal:" << withdrawal << ";";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_amount -= withdrawal;
	std::cout	<< "amount:" << Account::_amount << ";"
				<< "nb_deposit:" << Account::_nbDeposits << std::endl;
	return true;
}

int	Account::checkAmount( void ) const
{
	return Account::_amount;	
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "amount:" << Account::_amount << ";"
				<< "deposits:" << Account::_nbDeposits << ";"
				<< "withdrawals:" << Account::_nbWithdrawals << std::endl;
}
