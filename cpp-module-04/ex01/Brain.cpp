/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:44:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:47:52 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Brain assignation operator called" << std::endl;
	*this->_ideas = *rhs._ideas;
	return (*this);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > BRAIN_SIZE - 1)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}