/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 12:43:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input = "";
	
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			phoneBook.display();
			phoneBook.search();
		}
		else if (!input.empty())
			std::cout << "ADD, SEARCH or EXIT ?" << std::endl;
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}
