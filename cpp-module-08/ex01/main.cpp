/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/26 17:41:25 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int	main(void)
{

	std::cout << "Test with 100 random numbers" << std::endl;
	try {
		Span sp2 = Span(100);
		srand(time(NULL));
		std::vector<int> tmp;
		for (int i = 0; i < 100; i++)
			tmp.push_back(rand() % 1000);
		sp2.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Test with 101 numbers (should throw an exception)" << std::endl;
	/* Test with span of 100 */
	try {
		Span sp2 = Span(100);
		srand(time(NULL));
		std::vector<int> tmp;
		for (int i = 0; i < 101; i++)
			tmp.push_back(rand() % 1000);
		sp2.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	

	/* Test from subject */
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	return (0);
}
