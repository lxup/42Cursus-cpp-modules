/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:19 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:51:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	// std::cout << "Zombie has been created." << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
	return ;
}

void    Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}