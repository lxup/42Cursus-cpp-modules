/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:06:30 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 19:45:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	_target;
		void				beExecuted(void) const;
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
};

#endif // PRESIDENTIALPARDONFORM_HPP