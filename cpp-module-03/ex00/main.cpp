/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 11:18:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap	titouan("Titouan");
	ClapTrap	titouanclone = titouan;
	ClapTrap	badguys[5];

	titouan.attack("Jean"); // 1st attack
	titouan.attack(badguys[0].getName()); // 2nd attack
	titouan.attack(badguys[1].getName()); // 3rd attack
	titouan.attack(badguys[2].getName()); // 4th attack
	titouan.attack(badguys[3].getName()); // 5th attack
	titouan.attack(badguys[4].getName()); // 6th attack
	titouan.attack("Jean"); // 7th attack
	titouan.attack("Jean"); // 8th attack
	titouan.attack("Jean"); // 9th attack
	titouan.attack("Jean"); // 10th attack
	titouan.attack("Jean"); // out of energy
	titouan.takeDamage(9); // 1 hp left
	titouan.attack("Jean"); // out of energy
	titouan.takeDamage(1); // 0 hp left
	titouan.attack("Jean"); // already dead
	titouanclone.attack("Jean"); // 1st attack
	titouan.beRepaired(10); // already dead
}