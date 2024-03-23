/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:40:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output the animal sound!

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();
	
	std::cout << metaWrong->getType() << " " << std::endl;
	std::cout << iWrong->getType() << " " << std::endl;

	iWrong->makeSound(); //will output the wrong animal sound!
	metaWrong->makeSound(); //will output the wrong animal sound!
	
	delete meta;
	delete j;
	delete i;
	delete metaWrong;
	delete iWrong;
	return (0);
}
