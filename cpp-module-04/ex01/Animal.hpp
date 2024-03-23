/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:19:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:31:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal & operator=(Animal const &rhs);

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif // ANIMAL_HPP
