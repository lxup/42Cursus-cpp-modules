/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:03:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 12:17:34 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "LibraryConverter.hpp"

# include <iostream>
# include <string>
# include <limits.h>
# include <cfloat>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const std::string &input);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);

		static e_type		_getType(std::string &input);

		// Conditions
		static bool		_isChar(std::string &input);
		static bool		_isInt(std::string &input);
		static bool		_isFloat(std::string &input);
		static bool		_isDouble(std::string &input);
		static bool		_isLiteral(std::string &input);

		// Converters
		static char		_convertChar(std::string const &input);
		static int		_convertInt(std::string const &input);
		static float	_convertFloat(std::string const &input);
		static double	_convertDouble(std::string const &input);

		// Prints
		static void		_printChar(std::string &input);
		static void		_printInt(std::string &input);
		static void		_printFloat(std::string &input);
		static void		_printDouble(std::string &input);

		// Utils
		static std::string	_getTypeString(e_type type);
		
	public:
		static void		convert(std::string &input);
		static void		convert(std::string &input, bool debug);

		class	InputTypeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // SCALARCONVERTER_HPP
