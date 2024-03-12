/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 19:03:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie( void );
		~Zombie( void );
		void	announce( void ) const;
		void	setName( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP