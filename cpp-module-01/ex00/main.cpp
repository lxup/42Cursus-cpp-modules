/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 19:04:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "On the stack" << std::endl;
    std::cout << "Zombie: " << std::flush;
    std::cin >> name;

    Zombie zombie1(name);
    
    std::cout << "On the heap" << std::endl;
    std::cout << "Zombie: " << std::flush;
    std::cin >> name;

    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    std::cout << "Go randomChump()" << std::endl;
    randomChump("randi");
    return 0;
}