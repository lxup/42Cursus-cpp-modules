/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:35:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input = "";
	
	std::cout << "ADD, SEARCH or EXIT ?" << std::endl;
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
		if (std::cin.eof()) {
			std::cout << "\1\033[1;31m\2Exiting...\1\033[0m\2" << std::endl;
			break;
		}
	}
	return (0);
}
