/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/20 19:23:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "U should use like that: ./convert <num1> [<num2> ...]" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		try {
			std::string str = av[i];
			ScalarConverter::convert(str);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		if (ac > 2 && i < ac - 1)
			std::cout << "# =============================== #" << std::endl;
	}
	return (0);
}
