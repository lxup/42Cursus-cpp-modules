/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:06:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 20:48:02 by lquehec          ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more" << std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now" << std::endl;
	return ;
}

void	Harl::complain( std::string level )
{
	HarlFct fcts[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*fcts[i])();
	else if (level.size())
		std::cout << "Unknown level" << std::endl;
	return ;
}
