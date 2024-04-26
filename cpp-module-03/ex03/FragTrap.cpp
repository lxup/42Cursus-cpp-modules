/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:45:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 19:11:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_baseHitPoints = this->_hitPoints;
	this->_baseAttackDamage = this->_attackDamage;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap constructor with name " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "FragTrap copy constructor with name " << src.getName() << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "FragTrap assignation operator with name " << rhs.getName() << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor with name " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " is asking for a high five" << std::endl;
}
