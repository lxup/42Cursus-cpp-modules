/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:19:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap	titouan("Titouan");
	ScavTrap	jean("Jean");
	FragTrap	machin("Machin");

	titouan.attack(jean.getName()); // 1st attack
	jean.takeDamage(titouan.getAttackDamage()); // Jean has taken 20 points of damage
	jean.attack(titouan.getName()); // 1st attack
	titouan.takeDamage(jean.getAttackDamage()); // Titouan has taken 15 points of damage
	titouan.attack(jean.getName()); // 2nd attack
	jean.takeDamage(titouan.getAttackDamage()); // Jean has taken 20 points of damage
	jean.guardGate(); // Jean has entered in Gate keeper mode
	titouan.attack(jean.getName()); // 3rd attack
	jean.takeDamage(titouan.getAttackDamage()); // Jean has taken 20 points of damage
	jean.guardGate(); // Jean has exited Gate keeper mode
	machin.attack(jean.getName()); // 1st attack
	jean.takeDamage(machin.getAttackDamage()); // Jean has taken 30 points of damage
	machin.highFivesGuys(); // Machin has requested a high five
	return (0);
}
