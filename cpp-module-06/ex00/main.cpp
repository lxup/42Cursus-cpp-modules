/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/19 16:56:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	bool	debug = false;
	if (ac == 1)
	{
		std::cout << "U should use like that: ./convert <num1> [<num2> ...]" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		if (i == 1 && str.substr(0, 2) == "--" && str.size() > 2 && isalpha(str[2]))
		{
			if (str.compare("--debug") == 0)
				debug = true;
			else
				std::cout << "Unknown option: " << str << std::endl;
			continue;
		}
		try {
			if (debug)
				ScalarConverter::convert(str, debug);
			else
				ScalarConverter::convert(str);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		if (ac > 2 && i < ac - 1)
			std::cout << "# =============================== #" << std::endl;
	}
	return (0);
}
