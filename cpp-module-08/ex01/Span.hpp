/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 17:57:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_v;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &src);
		
		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
		
		// Exception
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
				
};

#endif // SPAN_HPP
