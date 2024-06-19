/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:59:09 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/19 16:23:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

		virtual void		beExecuted(void) const = 0;
	public:
		AForm(const std::string & name, int gradeToSign);
		AForm(const std::string & name, int gradeToSign, int gradeToExec);
		AForm(const AForm & copy);
		virtual ~AForm(void);

		AForm & operator=(const AForm & rhs);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		void		beSigned(const Bureaucrat & bureaucrat);
		void		execute(const Bureaucrat & executor) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, const AForm & rhs);

#endif // FORM_HPP