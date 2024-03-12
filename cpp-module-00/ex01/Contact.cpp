/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:59:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 12:41:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::_getInput(std::string str) const
{
	std::string input = "";
	bool		isValid = false;

	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (!input.empty() && std::cin.good())
			isValid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	} while (!isValid);
	return (input);
}

void    Contact::create(void) {
    std::cin.ignore();
    this->_firstName = this->_getInput("First name: ");
    this->_lastName = this->_getInput("Last name: ");
    this->_nickName = this->_getInput("Nick name: ");
    this->_phoneNumber = this->_getInput("Phone number: ");
    this->_darkestSecret = this->_getInput("Darkest secret: ");
    std::cout << std::endl;
}

void	Contact::setIndex(int index)
{
	this->_index = index;
}

std::string	Contact::_truncate(std::string str) const
{
	if (str.length() > 10)
		str.substr(0, 9) + ".";
	return (str);
}

void	Contact::display(void) const
{
	if (this->_firstName.empty() && this->_lastName.empty() && this->_nickName.empty())
		return ;
	std::cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|                CONTACT #" << this->_index << "                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "First name\t" << this->_firstName << std::endl;
	std::cout << "Last name\t" << this->_lastName << std::endl;
	std::cout << "Nick name\t" << this->_nickName << std::endl;
	std::cout << std::endl;
}

void	Contact::view(void) const
{
	if (this->_firstName.empty() && this->_lastName.empty() && this->_nickName.empty())
		return ;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncate(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncate(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncate(this->_nickName) << std::flush;
	std::cout << "|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}