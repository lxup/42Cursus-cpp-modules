/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:44:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 19:11:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		unsigned int	_baseHitPoints;
		unsigned int	_baseAttackDamage;
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );
		
		FragTrap & operator=( FragTrap const & rhs );

		void	highFivesGuys( void );
};

#endif // FRAGTRAP_HPP
