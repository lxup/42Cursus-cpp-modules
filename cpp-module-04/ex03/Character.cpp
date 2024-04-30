/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:54:08 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/30 17:34:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("unknown") {
	// std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(std::string const &name) : _name(name) {
	// std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(Character const &src) {
	// std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	return;
}

Character::~Character(void) {
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	return;
}

Character & Character::operator=(Character const &src) {
	// std::cout << "Character assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < this->_inventorySize; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	// std::cout << "Character getName called" << std::endl;
	return (this->_name);
}

void Character::equip(AMateria* m) {
	// std::cout << "Character equip called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Equiped " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
	return;
}

void Character::unequip(int idx) {
	// std::cout << "Character unequip called" << std::endl;
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Nothing to unequip" << std::endl;
		return;
	}
	std::cout << "Unequiped " << this->_inventory[idx]->getType() << std::endl;
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	return;
}

void Character::use(int idx, ICharacter& target) {
	// std::cout << "Character use called" << std::endl;
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Nothing to use" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
	return;
}
