/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/18 12:58:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		// why not std::cerr? BECAUSE THE SUBJECT IS DUMB AF
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}
	try
	{
		RPN RPN(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
