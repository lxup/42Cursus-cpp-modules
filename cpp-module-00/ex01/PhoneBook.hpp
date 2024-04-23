/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:22:25 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/23 16:35:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <limits>

class PhoneBook {
	private:
		static const int	_maxContact = 8;
		Contact				_contacts[PhoneBook::_maxContact];
		int					_readInput(void) const;
	public: 
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	display(void) const;
		void	search(void) const;
		void	welcome(void) const;
};

#endif // PHONEBOOK_HPP