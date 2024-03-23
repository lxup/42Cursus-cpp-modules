/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:25:14 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 11:30:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardGate = false;
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "ScavTrap Constructor called with name " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardGate = false;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "ScavTrap Copy constructor called with name " << src.getName() << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "ScavTrap Assignation operator called with name " << rhs.getName() << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	this->_isGuardGate = rhs.getIsGuardGate();
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called with name " << this->_name << std::endl;
}

bool	ScavTrap::getIsGuardGate( void ) const
{
	return (this->_isGuardGate);
}

void	ScavTrap::guardGate( void )
{
	if (this->_isGuardGate == false)
	{
		std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
		this->_isGuardGate = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has exited Gate keeper mode" << std::endl;
		this->_isGuardGate = false;
	}
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy left and can't attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

