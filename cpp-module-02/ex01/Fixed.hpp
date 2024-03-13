/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:32 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/13 18:08:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_raw;
		static const int	_bits = 8;
	public:
		Fixed ( void );
		Fixed ( int const n );
		Fixed ( float const n );
		Fixed ( Fixed const & src );
		Fixed & operator=( Fixed const & rhs );
		~Fixed( void );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif // FIXED_HPP
