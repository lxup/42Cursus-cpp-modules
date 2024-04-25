/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:20 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/25 16:31:31 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// Increment and decrement operators
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	// Comparison operators
	Fixed c(5.05f);
	Fixed d(5.05f);

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	
	// Arithmetic operators
	Fixed e(5.05f);
	Fixed f(2.02f);
	
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "e + f: " << (e + f) << std::endl;
	std::cout << "e - f: " << (e - f) << std::endl;
	std::cout << "e * f: " << (e * f) << std::endl;
	std::cout << "e / f: " << (e / f) << std::endl;
	
	return 0;
}