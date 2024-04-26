/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:24:40 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 20:31:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Cat assignation operator called" << std::endl;
	this->_type = rhs.getType();
	this->_brain->setIdeas(rhs._brain->getIdeas());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAAAAAAaaaaaoooooOOOOUUUUUUUUuuuuUUUuUuUUuuu ........." << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
