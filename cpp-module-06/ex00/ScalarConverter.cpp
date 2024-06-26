/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/24 19:30:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const std::string &input) {
	(void)input;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

 e_type    ScalarConverter::_getType(std::string &input)
{
	if (_isChar(input))
		return CHAR;
	if (_isInt(input))
		return INT;
	if (_isFloat(input))
		return FLOAT;
	if (_isDouble(input))
		return DOUBLE;
	return UNKNOWN;
}

// Convert
void	ScalarConverter::convert(std::string &input)
{
	e_type	type;
	if (input.size() == 0)
		throw ScalarConverter::InputTypeException();
	type = _getType(input);
	// std::cout << "Input: " << input << std::endl;
	// std::cout << "Type: " << _getTypeString(type) << std::endl;
	if (type == UNKNOWN)
		throw ScalarConverter::InputTypeException();
	else if (type == CHAR)
	{
		if (!std::isprint(static_cast<int>(input.at(0))))
			std::cout << "char: Non displayable" << std::endl;
		else
			std:: cout << "char: '" << input << "'" << std::endl;
		std:: cout << "int: " << static_cast<int>(input.at(0)) << std::endl;
		std:: cout << "float: " << static_cast<float>(input.at(0)) << ".0f" << std::endl;
		std:: cout << "double: " << static_cast<double>(input.at(0)) << ".0" << std::endl;
		return ;		
	}
	_printChar(input);
	_printInt(input);
	_printFloat(input);
	_printDouble(input);
}

// Conditions
bool	ScalarConverter::_isChar(std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (input.at(0) > std::numeric_limits<char>::max() || input.at(0) < std::numeric_limits<char>::min())
		return (false);
	if (std::isdigit(input.at(0)))
		return (false);
	return (true);
}

bool	ScalarConverter::_isInt(std::string &input)
{
	int	j;

	j = 0;
	if (input[j] == '+' || input[j] == '-')
		j++;
	for (size_t i = j; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::_isFloat(std::string &input)
{
	int	j;
	int	dot;
	int	numbers;

	if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf"))
		return (true);
	if (input.at(input.length() - 1) != 'f')
		return (false);
	j = 0;
	dot = 0;
	if (input[j] == '+' || input[j] == '-')
		j++;
	numbers = 0;
	for (size_t i = j; i < input.length() - 1; i++)
	{
		if ((!std::isdigit(input[i]) && input[i] != '.') || dot > 1)
			return (false);
		if (input[i] == '.')
			dot++;
		if (std::isdigit(input[i]))
			numbers++;
	}
	if (!numbers || dot > 1)
		return (false);
	return (true);
}

bool	ScalarConverter::_isDouble(std::string &input)
{
	int	j;
	int	dot;
	int	numbers;

	if (!input.compare("-inf") || !input.compare("+inf") \
		|| !input.compare("nan"))
		return (true);
	j = 0;
	dot = 0;
	if (input[j] == '+' || input[j] == '-')
		j++;
	numbers = 0;
	for (size_t i = j; i < input.length(); i++)
	{
		if ((!std::isdigit(input[i]) && input[i] != '.') || dot > 1)
			return (false);
		if (input[i] == '.')
			dot++;
		if (std::isdigit(input[i]))
			numbers++;
	}
	if (!numbers || dot > 1)
		return (false);
	return (true);
}

bool	ScalarConverter::_isLiteral(std::string &input)
{
	if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf") || !input.compare("-inf") \
		|| !input.compare("+inf") || !input.compare("nan"))
		return (true);
	return (false);
}

// Converters
char	ScalarConverter::_convertChar(std::string const &input)
{
	return (static_cast<char>(LibraryConverter::ft_stoi(input)));
}

int	ScalarConverter::_convertInt(std::string const &input)
{
	return (static_cast<int>(LibraryConverter::ft_stoi(input)));
}

float	ScalarConverter::_convertFloat(std::string const &input)
{
	return (static_cast<float>(LibraryConverter::ft_stof(input)));
}

double	ScalarConverter::_convertDouble(std::string const &input)
{
	return (static_cast<double>(LibraryConverter::ft_stod(input)));
}

// Print
void	ScalarConverter::_printChar(std::string &input)
{
	double	d;
	char	c;

	try {
		if (_isLiteral(input))
			throw std::exception();
		c = _convertChar(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
		d = _convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	} catch (std::exception &e) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (d < CHAR_MIN || (input.compare(CHAR_MIN_STR) && d == CHAR_MIN)
		|| d > CHAR_MAX || (input.compare(CHAR_MAX_STR) && d == CHAR_MAX))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	ScalarConverter::_printInt(std::string &input)
{
	double	d;
	int		i;

	try {
		if (_isLiteral(input))
			throw std::exception();
		i = _convertInt(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
		d = _convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	} catch (std::exception &e) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (d < INT_MIN || (input.compare(INT_MIN_STR) && d == INT_MIN)
		|| d > INT_MAX || (input.compare(INT_MAX_STR) && d == INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::_printFloat(std::string &input)
{
	float	f;

	if (_isLiteral(input))
	{
		if (!input.compare("+inf") || !input.compare("-inf"))
			std::cout << "float: " << input << "f" << std::endl;
		else if (input.substr(input.size() - 1).compare("f"))
			std::cout << "float: " << input << "f" << std::endl;
		else
			std::cout << "float: " << input << std::endl;
		return ;
	}
	try {
		f = _convertFloat(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	} catch (std::exception &e) {
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (f < -FLT_MAX || f > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
}

void	ScalarConverter::_printDouble(std::string &input)
{
	double	d;

	if (_isLiteral(input))
	{
		if (!input.compare("+inf") || !input.compare("-inf"))
			std::cout << "double: " << input << std::endl;
		else if (input.substr(input.size() - 1).compare("f"))
			std::cout << "double: " << input << std::endl;
		else 
			std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		return ;
	}
	try {
		d = _convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	} catch (std::exception &e) {
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
	{
		if (d == static_cast<int>(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
}

// Utils
std::string	ScalarConverter::_getTypeString(e_type type)
{
	switch (type)
	{
		case CHAR:
			return "char";
		case INT:
			return "int";
		case FLOAT:
			return "float";
		case DOUBLE:
			return "double";
		default:
			return "unknown";
	}
}

// Exceptions
const char * ScalarConverter::InputTypeException::what() const throw()
{
	return ("Input type is unknown");
}
