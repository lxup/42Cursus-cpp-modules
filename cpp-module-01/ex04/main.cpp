/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:16:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 19:27:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
        std::cerr << "Make something like: ./Sed <filename> <to_find> <replace>." << std::endl;
        return (EXIT_FAILURE);
    }
	else
	{
        Sed   sed(av[1]);
        sed.replace(av[2], av[3]);
    }
    return (EXIT_SUCCESS);	
}
