/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:23:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:23:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog & operator=(Dog const &rhs);

		virtual void makeSound(void) const;
};

#endif // DOG_HPP
