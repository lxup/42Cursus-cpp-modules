/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:42:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/23 12:46:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define BRAIN_SIZE 100

class Brain
{
	private:
		std::string	_ideas[BRAIN_SIZE];
	public:
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);

		Brain & operator=(Brain const &rhs);

		std::string			getIdea(int i) const;
		void				setIdea(int i, std::string idea);
};

#endif // BRAIN_HPP
