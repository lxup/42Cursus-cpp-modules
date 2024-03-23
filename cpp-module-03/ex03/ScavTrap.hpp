/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:23:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:02:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool		_isGuardGate;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap( void );
		
		ScavTrap & operator=( ScavTrap const & rhs );

		void	guardGate( void );
		void	attack(std::string const & target);
		bool	getIsGuardGate( void ) const;
};

#endif // SCAVTRAP_HPP
