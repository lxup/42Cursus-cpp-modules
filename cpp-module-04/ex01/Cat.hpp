/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:24:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:24:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat & operator=(Cat const &rhs);

		virtual void makeSound(void) const;
};

#endif // CAT_HPP
