/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:18 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:52:44 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Adress of the string: " << &string << std::endl;
	std::cout << "Adress of the string with pointer: " << stringPTR << std::endl;
	std::cout << "Adress of the string with reference: " << &stringREF << std::endl;

	std::cout << "Value of the string: " << string << std::endl;
	std::cout << "Value of the string with pointer: " << *stringPTR << std::endl;
	std::cout << "Value of the string with reference: " << stringREF << std::endl;
	
	return 0;
}