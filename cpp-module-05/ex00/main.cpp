/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/19 16:41:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);
	std::cout << *bureaucrat << std::endl;
	// decremetGrade => exception "Grade is too low"
	try {
		bureaucrat->decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete bureaucrat;

	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 1);
	std::cout << *bureaucrat2 << std::endl;
	// incrementGrade => exception "Grade is too high"
	try {
		bureaucrat2->incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete bureaucrat2;
	return (0);
}