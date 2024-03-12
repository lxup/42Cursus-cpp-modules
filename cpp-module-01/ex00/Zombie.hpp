/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 18:38:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
		Zombie	*newZombie( std::string name );
		void	randomChump( std::string name );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif // ZOMBIE_HPP