/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:29:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 15:38:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>

class Array
{
	private:
		T		*_array;
		size_t	_size;
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for (size_t i = 0; i < n; i++)
				_array[i] = T();
		}
		Array(Array const &src) : _array(new T[src._size]), _size(src._size)
		{
			for (size_t i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		}
		~Array(void) { delete[] _array; }

		Array	&operator=(Array const &src)
		{
			if (this != &src)
			{
				T *tmp = new T[src._size];
				for (size_t i = 0; i < src._size; i++)
					tmp[i] = src._array[i];
				delete[] _array;
				_array = tmp;
				_size = src._size;
			}
			return (*this);
		}

		T		&operator[](size_t i)
		{
			if (i >= _size)
				throw std::exception();
			return (_array[i]);
		}

		size_t	size(void) const { return (_size); }
};

#endif // ARRAY_HPP
