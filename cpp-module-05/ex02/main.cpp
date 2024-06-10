/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:08:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 3);
	Bureaucrat	bureaucrat_cpy = bureaucrat;

	ShrubberyCreationForm	f1 = ShrubberyCreationForm("TIF");
	RobotomyRequestForm		f2 = RobotomyRequestForm("TH");
	PresidentialPardonForm	f3 = PresidentialPardonForm("Booba");
	
	try {
		bureaucrat.executeForm(f1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	bureaucrat.signForm(f1);
	bureaucrat.executeForm(f1);

	PresidentialPardonForm	f4 = f3;
	bureaucrat.signForm(f4);
	bureaucrat.executeForm(f4);

	try {
		bureaucrat.executeForm(f2);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	bureaucrat.signForm(f2);
	bureaucrat.executeForm(f2);
	return 0;
}