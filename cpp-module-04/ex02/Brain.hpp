/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:42:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/26 20:31:23 by lquehec          ###   ########.fr       */
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

		const std::string			getIdea(int i) const;
		const std::string			*getIdeas(void) const;
		void				setIdea(int i, std::string idea);
		void				setIdeas(const std::string *ideas);
};

#endif // BRAIN_HPP
