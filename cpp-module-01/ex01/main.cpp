/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 19:06:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZOMBIE_COUNT 5

int main( void ) {
    Zombie *horde = zombieHorde(ZOMBIE_COUNT, "Zombie");
    
    for (int i = 0; i < ZOMBIE_COUNT; i++)
    {
        horde[i].announce();
    }

    delete [] horde;
    return 0;
}