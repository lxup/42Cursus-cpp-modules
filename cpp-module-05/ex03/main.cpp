/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:36:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 3);
	Bureaucrat	bureaucrat_cpy = bureaucrat;

	ShrubberyCreationForm	f1 = ShrubberyCreationForm("TIF");
	RobotomyRequestForm		f2 = RobotomyRequestForm("TH");
	PresidentialPardonForm	f3 = PresidentialPardonForm("Booba");
	
	bureaucrat.executeForm(f1);
	bureaucrat.signForm(f1);
	bureaucrat.executeForm(f1);

	PresidentialPardonForm	f4 = f3;
	bureaucrat.signForm(f4);
	bureaucrat.executeForm(f4);


	bureaucrat.executeForm(f2);
	bureaucrat.signForm(f2);
	bureaucrat.executeForm(f2);

	AForm *f5;
	f5 = Intern().makeForm("ShrubberyCreationForm", "TIF");
	f5 = Intern().makeForm("robotomy request", "TH");
	
	return 0;
}