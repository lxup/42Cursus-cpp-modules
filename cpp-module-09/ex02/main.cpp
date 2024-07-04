/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 20:14:55 by lquehec          ###   ########.fr       */
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

		PmergeMe<std::list<int> >	pm2(av + 1);

		pm2.sort();

		std::cout << "After sort:\t";
		pm2.print();
		std::cout << std::endl;

		pm.time();
		pm2.time();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (EXIT_SUCCESS);
}

/* ============================ CUSTOM MAIN ============================ */
// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		std::cout << "Usage: ./PmergeMe [+int1] [+int2] ... [+intN]" << std::endl;
// 		return (EXIT_FAILURE);
// 	}
// 	try
// 	{
// 		PmergeMe<std::vector<int> >	pm(av + 1);
// 		// std::cout << "Before sort:\t" << pm << std::endl;
// 		std::cout << "Before sort (std::" << pm.getType() << ")\t➡️\t";
// 		pm.print();
// 		std::cout << std::endl;

// 		pm.sort();

// 		std::cout << "After sort (std::" << pm.getType() << ")\t➡️\t";
// 		pm.print();
// 		std::cout << std::endl;

// 		PmergeMe<std::list<int> >	pm2(av + 1);
// 		std::cout << "Before sort (std::" << pm2.getType() << ")\t➡️\t";
// 		pm2.print();
// 		std::cout << std::endl;

// 		pm2.sort();

// 		std::cout << "After sort (std::" << pm2.getType() << ")\t➡️\t";
// 		pm2.print();
// 		std::cout << std::endl;

// 		// Deque
// 		PmergeMe<std::deque<int> >	pm3(av + 1);
// 		std::cout << "Before sort (std::" << pm3.getType() << ")\t➡️\t";
// 		pm3.print();
// 		std::cout << std::endl;
		
// 		pm3.sort();

// 		std::cout << "After sort (std::" << pm3.getType() << ")\t➡️\t";
// 		pm3.print();
// 		std::cout << std::endl;

// 		pm.time();
// 		pm2.time();
// 		pm3.time();
		
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Error: " << e.what() << std::endl;
// 		return (1);
// 	}
// 	return (EXIT_SUCCESS);
// }
