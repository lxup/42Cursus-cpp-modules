/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:29:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:37:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <limits>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;

		std::string	_getInput(std::string str) const;
		std::string	_truncate(std::string str) const;
	public:
		Contact(void);
		~Contact(void);
		void		create(void);
		void		display(void) const;
		void		view(void) const;
		void		setIndex(int index);
};

#endif // CONTACT_HPP