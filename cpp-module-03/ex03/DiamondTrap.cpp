/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:50:27 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 19:14:57 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = this->ScavTrap::_name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_baseHitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_baseAttackDamage;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	std::cout << "DiamondTrap copy constructor called with name " << src.getName() << std::endl;
	*this = src;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "DiamondTrap assignation operator called with name " << rhs.getName() << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called with name " << this->_name << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
