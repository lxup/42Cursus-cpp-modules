/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:06 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 15:20:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>

T	&min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>

T	&max(T &a, T &b)
{
	return (a > b ? a : b);
}

#endif // WHATEVER_HPP
