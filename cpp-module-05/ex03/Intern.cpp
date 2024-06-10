/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:22:23 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:34:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

static AForm	*createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string const & target)
{
	AForm	*newForm = NULL;
	const	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formCreators[])(std::string const & target) = {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};

	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); i++)
	{
		if (name == forms[i])
		{
			newForm = formCreators[i](target);
			break;
		}
	}
	if (!newForm)
		std::cout << "Form with name " << name << " not found." << std::endl;
	return (newForm);
}
