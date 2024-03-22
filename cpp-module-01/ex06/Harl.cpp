/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:06:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 21:02:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	// std::cout << "Harl created" << std::endl;
	return ;
}

Harl::~Harl( void )
{
	// std::cout << "Harl destroyed" << std::endl;
	return ;
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n" << std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable ! I want to speak to the manager now.\n" << std::endl;
	return ;
}

void	Harl::complain( std::string level )
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			harlLevel = -1;

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
		{
			harlLevel = i;
			break ;
		}
	}
	switch (harlLevel)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break ;
		default:
			if (level.size())
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}
