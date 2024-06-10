/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:30:48 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:42:36 by lquehec          ###   ########.fr       */
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

	AForm	*f1 = intern.makeForm("Shrubbery Creation", "TIF");
	AForm	*f2 = intern.makeForm("Robotomy Request", "TH");
	AForm	*f3 = intern.makeForm("Presidential Pardon", "Booba");
	
	bureaucrat.executeForm(*f1);
	bureaucrat.signForm(*f1);
	bureaucrat.executeForm(*f1);

	bureaucrat.executeForm(*f2);
	bureaucrat.signForm(*f2);
	bureaucrat.executeForm(*f2);

	bureaucrat.executeForm(*f3);
	bureaucrat.signForm(*f3);
	bureaucrat.executeForm(*f3);

	intern.makeForm("Form does not exist", "Booba");

	delete f1;
	delete f2;
	delete f3;
	
	return 0;
}