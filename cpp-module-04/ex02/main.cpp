/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 20:55:55 by lquehec          ###   ########.fr       */
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

	Animal	*cat = new Cat();
	cat->makeSound();
	delete cat;

	// not possible to create an instance of an abstract class
	// Animal	ko = Animal();
	// ko.makeSound();
	// Animal	dog = Dog();
	// dog.makeSound();

	return (0);

}
