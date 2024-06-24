/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/24 20:13:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// test with string and int (not possible)
	// std::string e = "chaine1";
	// int			f = 42;
	
	// ::swap(e, f);
	// std::cout << "e = " << e << ", f = " << f << std::endl;
	// std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	// std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	
	return (0);
}
