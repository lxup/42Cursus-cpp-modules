/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 16:01:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> vec;
	
	// Assign 10 values to the vector
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	
	// Test good value
	std::cout << "Test good value: " << std::endl;
	try
	{
		easyfind(vec, 5);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	try
	{
		easyfind(vec, 9);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}

	// Test wrong value
	std::cout << "Test wrong value: " << std::endl;
	try
	{
		easyfind(vec, 10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	try
	{
		easyfind(vec, 11);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	return (0);
}
