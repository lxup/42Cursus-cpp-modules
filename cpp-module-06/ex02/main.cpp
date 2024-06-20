/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/20 16:03:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(NULL));
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A generated" << std::endl;
			return (new A);
		case 1:
			std::cout << "B generated" << std::endl;
			return (new B);
		case 2:
			std::cout << "C generated" << std::endl;
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	// std::cout << "Identify using pointer to Base" << std::endl;
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
	return ;
}

void	identify(Base &p)
{
	// std::cout << "Identify using reference to Base" << std::endl;
	try
	{
		if (dynamic_cast<A*>(&p) != NULL)
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(&p) != NULL)
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(&p) != NULL)
			std::cout << "C" << std::endl;
		else
			throw std::exception();
	}
	catch (std::exception &e) {}
}

int	main(void)
{
	std::cout << "Generating a random class derived from Base" << std::endl;
	Base	*base = generate();
	std::cout << "Identifying the class as pointer to Base" << std::endl;
	identify(base);
	std::cout << "Identifying the class as reference to Base" << std::endl;
	identify(*base);
	delete base;
	return (0);
}
