/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:23:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 19:19:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "wwwWWWOOOOOAAAAaaaaaaffFFFFFF zbiiiiiiiii......" << std::endl;
}
