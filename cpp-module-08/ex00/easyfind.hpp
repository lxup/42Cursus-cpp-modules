/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 16:00:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
void	easyfind(T &container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	std::cout << "Value found: " << *it << std::endl;
}

#endif // EASYFIND_HPP
