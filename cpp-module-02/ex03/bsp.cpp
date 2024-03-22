/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:54:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:57:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed const a)
{
	return (a < 0 ? (a * -1) : a);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc = abs(area(a, b, c));
	Fixed	abp = abs(area(a, b, point));
	Fixed	acp = abs(area(a, c, point));
	Fixed	bcp = abs(area(b, c, point));
	return (abc == abp + acp + bcp);
}