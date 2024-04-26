/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:24:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 19:38:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat & operator=(Cat const &rhs);

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif // CAT_HPP
