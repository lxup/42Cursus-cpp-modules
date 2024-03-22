/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/13 11:26:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_raw = 0;
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const raw )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << this->_bits;
	return ;
}

Fixed::Fixed( float const raw )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * (1 << this->_bits));
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
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


// Comparison operators
bool	Fixed::operator>(Fixed const & rhs) const
{
	return this->_raw > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return this->_raw < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return this->_raw >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return this->_raw <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return this->_raw == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return this->_raw != rhs.getRawBits();
}

// Arithmetic operators
Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment and decrement operators
Fixed &	Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &	Fixed::operator--(void)
{
	this->_raw--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Min and Max functions
Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b) ? a : b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b) ? a : b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a < b) ? a : b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b) ? a : b;
}
