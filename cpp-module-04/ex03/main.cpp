/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:36:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/30 18:21:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	defaultTest(void)
{
	std::cout << "Default test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}

int	customTest(void)
{
	std::cout << "Custom test" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // This one should not be learned

	AMateria* tmp;
	tmp = src->createMateria("ice");

	ICharacter* zbi = new Character("zbi");
	zbi->equip(tmp);
	zbi->use(0, *zbi);
	zbi->use(249844846, *zbi); // This one should not work
	zbi->use(-454654, *zbi); // This one should not work
	zbi->use(2, *zbi); // This one should not work
	zbi->unequip(0);
	zbi->use(0, *zbi); // This one should not work
	zbi->unequip(57527057); // This one should not work
	delete src;
	delete zbi;
	return (0);
}

int main(void)
{
	defaultTest();
	customTest();
	return (0);
}
