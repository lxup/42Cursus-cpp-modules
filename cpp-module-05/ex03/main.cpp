/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/25 19:55:01 by lquehec          ###   ########.fr       */
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

	Intern	intern = Intern();

	std::cout << "Intern creates:" << std::endl;
	AForm	*f1 = intern.makeForm("Shrubbery Creation", "TIF");
	AForm	*f2 = intern.makeForm("Robotomy Request", "TH");
	AForm	*f3 = intern.makeForm("Presidential Pardon", "Booba");
	std::cout << std::endl;

	std::cout << std::endl << "Bureaucrat executes:" << std::endl;
	bureaucrat.executeForm(*f1);
	bureaucrat.signForm(*f1);
	bureaucrat.executeForm(*f1);

	bureaucrat.executeForm(*f2);
	bureaucrat.signForm(*f2);
	bureaucrat.executeForm(*f2);

	bureaucrat.executeForm(*f3);
	bureaucrat.signForm(*f3);
	bureaucrat.executeForm(*f3);
	std::cout << std::endl;

	std::cout << "Intern creates the form that does not exist:" << std::endl;
	AForm *f4 = intern.makeForm("Form does not exist", "Booba");
	std::cout << std::endl;

	std::cout << "Intern creates the form that do exist:" << std::endl;
	AForm *f5 = intern.makeForm("Presidential Pardon", "Booba");

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	
	return 0;
}