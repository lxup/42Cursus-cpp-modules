/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:17:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/24 17:43:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->setType(type);
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const	&Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
	return ;
}
