/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:17:58 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/18 12:53:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>

class RPN
{
	private:
		std::stack<double> _stack;

		static bool	_isOperator(char c);

		void	_debugPrintStack(void);
	public:
		RPN(std::string input);
		RPN(RPN const &src);
		~RPN(void);

		RPN &operator=(RPN const &src);

		void	calculate(void);

		// Exceptions
		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // RPN_HPP
