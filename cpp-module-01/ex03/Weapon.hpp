/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:17:57 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 19:22:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon( std::string type );
		~Weapon( void );
		const std::string	&getType( void ) const;
		void				setType( std::string type );
};

#endif // WEAPON_HPP