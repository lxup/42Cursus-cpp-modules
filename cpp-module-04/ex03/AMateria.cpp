/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:42:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/30 17:58:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("unknown") {
	// std::cout << "AMateria default constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << "AMateria constructor called" << std::endl;
	return;
}

AMateria::AMateria(AMateria const &src) {
	*this = src;
	return;
}

AMateria::~AMateria(void) {
	// std::cout << "AMateria destructor called" << std::endl;
	return;
}

AMateria & AMateria::operator=(AMateria const &src) {
	// std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const & AMateria::getType() const {
	// std::cout << "AMateria getType called" << std::endl;
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	// std::cout << "AMateria use called" << std::endl;
	(void)target;
	std::cout << "Im virtual so I can't do anything" << std::endl;
	return;
}
