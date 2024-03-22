/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:03:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 20:50:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl        harl;
    std::string input;

    if (ac >= 2)
		harl.complain(av[1]);
	else
		harl.complain("");
    return (EXIT_SUCCESS);	
}
