/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:49:51 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 19:13:12 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): _x(0), _y(0)
{
	// std::cout << "Point created" << std::endl;
	return ;
}

Point::Point( Fixed const x, Fixed const y ): _x(x), _y(y)
{
	// std::cout << "Point created with x: " << x << " and y: " << y << std::endl;
	return ;
}

Point::Point( Point const & src ): _x(src.getX()), _y(src.getY())
{
	// std::cout << "Point created with x: " << src.getX() << " and y: " << src.getY() << std::endl;
	return ;
}

Point::~Point( void )
{
	// std::cout << "Point destroyed" << std::endl;
	return ;
}

Point &	Point::operator=( Point const & rhs )
{
	if (this != &rhs)
	{
		( Fixed )this->_x = rhs.getX();
		( Fixed )this->_y = rhs.getY();
	}
	return *this;
}

Fixed	Point::getX( void ) const
{
	return this->_x;
}

Fixed	Point::getY( void ) const
{
	return this->_y;
}

