/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:58:25 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 20:02:43 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
{	
	bool	prevIsDigit = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		// _debugPrintStack();
		if (isdigit(input[i]) || ((input[i] == '-' || input[i] == '+') && isdigit(input[i + 1])))
		{
			if (prevIsDigit)
				throw InvalidExpressionException();
			int sign = 1;
			if (input[i] == '-' || input[i] == '+')
			{
				if (input[i] == '-')
					sign = -sign;
				i++;
			}
			int number = input[i] - '0';
			this->_stack.push(number * sign);
			prevIsDigit = true;
		}
		else
		{
			prevIsDigit = false;
			if (_isOperator(input[i]))
			{
				if (this->_stack.size() < 2)
					throw InvalidExpressionException();
				double a = this->_stack.top();
				this->_stack.pop();
				double b = this->_stack.top();
				this->_stack.pop();
				if (input[i] == '+')
					this->_stack.push(b + a);
				else if (input[i] == '-')
					this->_stack.push(b - a);
				else if (input[i] == '*')
					this->_stack.push(b * a);
				else if (input[i] == '/')
					this->_stack.push(b / a);
				else if (input[i] == '^')
					this->_stack.push(pow(b, a));
				else if (input[i] == '%')
					this->_stack.push(fmod(b, a));
			} else if (iswspace(input[i]))
				continue;
			else
				throw InvalidExpressionException();
		}
	}
	if (this->_stack.size() != 1)
		throw InvalidExpressionException();
	std::cout << this->_stack.top() << std::endl;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src)
		this->_stack = src._stack;
	return (*this);
}


// Conditions
bool	RPN::_isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

// Debug
void	RPN::_debugPrintStack(void)
{
	std::stack<double>	tmp = this->_stack;

	std::cout << "#======================= STACK =======================#" << std::endl;
	while (!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
	std::cout << "#====================================================#" << std::endl;
}

// Exceptions
const char* RPN::InvalidExpressionException::what() const throw()
{
	return ("Invalid expression");
}
