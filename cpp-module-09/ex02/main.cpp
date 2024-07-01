/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/01 12:48:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>
# include <list>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe [+int1] [+int2] ... [+intN]" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		PmergeMe<std::vector<int> >	pm(av + 1);
		// std::cout << "Before sort:\t" << pm << std::endl;
		std::cout << "Before sort:\t";
		pm.print();
		std::cout << std::endl;

		pm.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (EXIT_SUCCESS);
}
