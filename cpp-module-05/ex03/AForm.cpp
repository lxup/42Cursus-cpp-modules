/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:17:00 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 20:43:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string & name, int gradeToSign) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(0)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string & name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	
}

AForm::~AForm(void)
{
	return ;
}

AForm& AForm::operator=(const AForm & rhs)
{
	if (this != &rhs)
		_signed = rhs.getSigned();
	return (*this);
}

std::string AForm::getName(void) const
{
	return(_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::GradeTooLowException();
	else if (!this->_signed)
		throw AForm::FormNotSignedException();
	else
		this->beExecuted();
}

std::ostream & operator<<(std::ostream & o, const AForm & rhs)
{
	o << "AForm" << std::endl;
	o << "AForm name: " << rhs.getName() << std::endl
		<< "Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "Grade to exec: " << rhs.getGradeToExec() << std::endl;
	return (o);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

