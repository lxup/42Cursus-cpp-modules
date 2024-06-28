/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:04:10 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/26 17:39:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src) : _n(src._n), _v(src._v) {}

Span::~Span(void) {}

Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_v = src._v;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_v.size() >= this->_n)
		throw Span::SpanFullException();
	this->_v.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_n)
		throw Span::SpanFullException();
	this->_v.insert(this->_v.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	int					span;
	std::vector<int>	tmp;

	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < span)
			span = tmp[i] - tmp[i - 1];
	}
	return (span);
}

int	Span::longestSpan(void)
{
	std::vector<int>	tmp;

	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

// Exceptions
const char* Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}

const char* Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}
