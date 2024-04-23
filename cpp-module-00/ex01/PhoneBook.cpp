/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:56:26 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:38:21 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{	
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	static int index;

	if (index == this->_maxContact)
		index = 0;
	this->_contacts[index % this->_maxContact].create();
	this->_contacts[index % this->_maxContact].setIndex(index);
	index++;
}

void	PhoneBook::display(void) const
{
	std::cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|                 PHONEBOOK                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nick name";
	std::cout << "|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0; i < this->_maxContact; i++)
		this->_contacts[i].view();
	std::cout << std::endl;
}

int	PhoneBook::_readInput(void) const
{
	int		index = -1;
	bool	isValid = false;

	do
	{
		std::cout << "Search index: " << std::flush;
		std::cin >> index;
		if (std::cin.good() && index >= 0 && index < this->_maxContact)
			isValid = true;
		else if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "\1\033[1;31m\2Go back...\1\033[0m\2" << std::endl;
			return (-1);
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index, please try again" << std::endl;
		}
	} while (!isValid);
	return (index);
}

void	PhoneBook::search(void) const
{
	int index;

	index = this->_readInput();
	if (index >= 0 && index < this->_maxContact)
		this->_contacts[index].display();
}


