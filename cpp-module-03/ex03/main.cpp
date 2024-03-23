/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:07:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	ClapTrap	titouan("Titouan");
	ScavTrap	jean("Jean");
	FragTrap	machin("Machin");
	DiamondTrap	diamond("Diamond");

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
	diamond.whoAmI(); // I am Diamond
	diamond.attack(machin.getName()); // 1st attack
	machin.takeDamage(diamond.getAttackDamage()); // Machin has taken 30 points of damage
	diamond.highFivesGuys(); // Diamond has requested a high five
	diamond.guardGate(); // Diamond has entered in Gate keeper mode
	diamond.guardGate(); // Diamond has exited Gate keeper mode
	diamond.beRepaired(10); // Diamond has been repaired by 10 points
}
