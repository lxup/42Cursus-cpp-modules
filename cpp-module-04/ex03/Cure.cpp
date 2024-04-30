/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:03:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/30 17:34:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure::Cure(Cure const &src) : AMateria(src) {
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
	return;
}

Cure::~Cure(void) {
	// std::cout << "Cure destructor called" << std::endl;
	return;
}

Cure & Cure::operator=(Cure const &src) {
	// std::cout << "Cure assignation operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure * Cure::clone() const {
	// std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	// std::cout << "Cure use called" << std::endl;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return;
}
