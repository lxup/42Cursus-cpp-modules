/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 20:42:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define ANIMAL_COUNT 4

int main( void ) {
	Animal *animals[ANIMAL_COUNT];

	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "BORRDEEEEEEEEEEEEEEEEEEELLLLLLLLL");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_COUNT; i++)
		delete animals[i];
	return (0);
}
