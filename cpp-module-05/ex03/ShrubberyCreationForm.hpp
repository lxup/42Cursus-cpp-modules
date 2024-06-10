/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:12 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:44:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	_target;
		void				beExecuted(void) const;
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

#endif // SHRUBBERYCREATIONFORM_HPP