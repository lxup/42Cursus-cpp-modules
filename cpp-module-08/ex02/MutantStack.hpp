/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:22:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/26 19:13:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {}
		~MutantStack(void) {}

		MutantStack &operator=(MutantStack const &src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		iterator	begin(void) { return (std::stack<T>::c.begin()); }
		const_iterator	begin(void) const { return (std::stack<T>::c.begin()); }
		iterator	end(void) { return (std::stack<T>::c.end()); }
		const_iterator	end(void) const { return (std::stack<T>::c.end()); }
};

#endif // MUTANTSTACK_HPP
