/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:19 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/25 17:05:23 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point( void );
		Point( Point const & src );
		Point( Fixed const x, Fixed const y );
		// Point( float const x, float const y );
		~Point( void );

		Point & operator=( Point const & rhs );

		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP

