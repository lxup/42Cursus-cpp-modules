/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:03:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 20:51:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <iostream>

class Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level );
};

#endif // HARL_HPP