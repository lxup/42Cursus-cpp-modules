/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:03:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 20:47:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl        harl;
    std::string input;

    do
    {
        std::cout << "Harl: ";
        std::getline(std::cin, input);
        if (input.compare("EXIT"))
            harl.complain(input);
    } while (input.compare("EXIT"));
    return (EXIT_SUCCESS);	
}
