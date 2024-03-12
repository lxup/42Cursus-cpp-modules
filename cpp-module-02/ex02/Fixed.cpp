/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/12 20:58:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_raw = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const raw )
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << this->_bits;
	return ;
}

Fixed::Fixed( float const raw )
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * (1 << this->_bits));
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->_raw;
}

void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return (float)this->_raw / (1 << this->_bits);
}

int		Fixed::toInt( void ) const
{
	return this->_raw >> this->_bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
