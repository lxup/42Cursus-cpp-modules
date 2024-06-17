/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 15:37:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	printElement(T const &element)
{
	std::cout << element << std::endl;
}

int	main(void)
{
	int 		arrayOfInt[] = {1, 2, 3, 4, 5};
	std::string arrayOfString[] = {"Hello", "World", "!"};

	iter(arrayOfInt, 5, printElement);
	iter(arrayOfString, 3, printElement);
	return (0);
}
