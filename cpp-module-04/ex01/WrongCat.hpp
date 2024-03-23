/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:27:04 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:27:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat(void);

		WrongCat & operator=(WrongCat const &rhs);

		void makeSound(void) const;
};

#endif // WRONGCAT_HPP
