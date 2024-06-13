/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:03:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/13 18:42:25 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL,
	UNKNOWN
};

class ScalarConverter
{
	private:
		std::string	_input;
		e_type		_inputType;

		char		_c;
		int			_i;
		float		_f;
		double		_d;

		void		_convert(const char *input);
		
	public:
		ScalarConverter(void);
		ScalarConverter(const char *input);
		ScalarConverter(const std::string &input);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);

		std::string	getInput(void) const;
		e_type		getInputType(void) const;
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;

		void		setInput(const char *input);
		void		setInputType(void);
		void		setChar(char c);
		void		setInt(int i);
		void		setFloat(float f);
		void		setDouble(double d);

		bool		isChar(void) const;
		bool		isInt(void) const;
		bool		isFloat(void) const;
		bool		isDouble(void) const;
		bool		isLiteral(void) const;
		

		void		printChar(void) const;
		void		printInt(void) const;
		void		printFloat(void) const;
		void		printDouble(void) const;

		class	InputTypeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, const ScalarConverter & rhs);

#endif // SCALARCONVERTER_HPP