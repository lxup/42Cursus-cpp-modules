/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:32 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 20:40:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_raw;
		static const int	_bits = 8;
	public:
		Fixed ( void );
		Fixed ( Fixed const & src );
		Fixed & operator=( Fixed const & rhs );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif // FIXED_HPP