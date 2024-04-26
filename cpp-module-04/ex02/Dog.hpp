/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:23:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 20:51:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog & operator=(Dog const &rhs);

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif // DOG_HPP
