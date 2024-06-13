/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:04:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/13 19:09:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _c('\0'), _i(0), _f(0.0f), _d(0.0)
{
}

ScalarConverter::ScalarConverter(const char *input) : _c('\0'), _i(0), _f(0.0f), _d(0.0)
{
	this->_convert(input);
}

ScalarConverter::ScalarConverter(const std::string &input) : _c('\0'), _i(0), _f(0.0f), _d(0.0)
{
	this->_convert(input.c_str());
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this != &src)
	{
		this->_c = src.getChar();
		this->_i = src.getInt();
		this->_f = src.getFloat();
		this->_d = src.getDouble();
	}
	return (*this);
}

std::string ScalarConverter::getInput(void) const
{
	return (this->_input);
}

e_type ScalarConverter::getInputType(void) const
{
	return (this->_inputType);
}

char ScalarConverter::getChar(void) const
{
	return (this->_c);
}

int ScalarConverter::getInt(void) const
{
	return (this->_i);
}

float ScalarConverter::getFloat(void) const
{
	return (this->_f);
}

double ScalarConverter::getDouble(void) const
{
	return (this->_d);
}

void ScalarConverter::setInput(const char *input)
{
	this->_input = input;
}

void    ScalarConverter::setInputType(void) {
    if (isChar()) {
        this->_input = CHAR;
    } else if (isInt()) {
        this->_input = INT;
    } else if (isFloat()) {
        this->_input = FLOAT;
    } else if (isDouble()) {
        this->_input = DOUBLE;
    } else if (isLiteral()) {
        this->_input = LITERAL;
    } else {
        this->_input = UNKNOWN;
    }
}

void ScalarConverter::setChar(char c)
{
	this->_c = c;
}

void ScalarConverter::setInt(int i)
{
	this->_i = i;
}

void ScalarConverter::setFloat(float f)
{
	this->_f = f;
}

void ScalarConverter::setDouble(double d)
{
	this->_d = d;
}

// Convert
void	ScalarConverter::_convert(const char *input)
{
	this->setInput(input);
	this->setInputType();
	if (this->getInputType() == UNKNOWN)
		throw ScalarConverter::InputTypeException();
	switch (this->_inputType)
	{
		case CHAR:
			this->_c = this->_input[0];
			this->_i = static_cast<int>(this->_c);
			this->_f = static_cast<float>(this->_c);
			this->_d = static_cast<double>(this->_c);
			break;
		case INT:
			this->_i = std::stoi(this->_input);	
			this->_c = static_cast<char>(this->_i);
			this->_f = static_cast<float>(this->_i);
			this->_d = static_cast<double>(this->_i);
			break;
		case FLOAT:
			this->_f = std::stof(this->_input);
			this->_c = static_cast<char>(this->_f);
			this->_i = static_cast<int>(this->_f);
			this->_d = static_cast<double>(this->_f);
			break;
		case DOUBLE:
			this->_d = std::stod(this->_input);
			this->_c = static_cast<char>(this->_d);
			this->_i = static_cast<int>(this->_d);
			this->_f = static_cast<float>(this->_d);
			break;
		default:
			break;
	}
}

// Conditions
bool	ScalarConverter::isChar(void) const
{
	if (this->_input.length() == 1 && std::isprint(this->_input[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(void) const
{
	int	j;

	j = 0;
	if (this->_input[j] == '+' || this->_input[j] == '-')
		j++;
	for (size_t i = j; i < this->_input.length(); i++)
	{
		if (!std::isdigit(this->_input[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(void) const
{
	int	j;
	int	dot;

	if ( this->_input.find( '.' ) == std::string::npos || !this->_input.find( '.' )
		|| this->_input.back() != 'f' || this->_input.find( '.' ) == this->_input.length() - 2 )
        return false;
	j = 0;
	dot = 0;
	if (this->_input[j] == '+' || this->_input[j] == '-')
		j++;
	for (size_t i = j; i < this->_input.length() - 1; i++)
	{
		if ((!std::isdigit(this->_input[i]) && this->_input[i] != '.') || dot > 1)
			return (false);
		if (this->_input[i] == '.')
			dot++;
	}
	return (true);
}

bool	ScalarConverter::isDouble(void) const
{
	int	j;
	int	dot;

	if (this->_input.find( '.' ) == std::string::npos || this->_input.find( '.' ) == 0 
        || this->_input.find( '.' ) == this->_input.length() - 1 )
        return false;
	j = 0;
	dot = 0;
	if (this->_input[j] == '+' || this->_input[j] == '-')
		j++;
	for (size_t i = j; i < this->_input.length(); i++)
	{
		if ((!std::isdigit(this->_input[i]) && this->_input[i] != '.') || dot > 1)
			return (false);
		if (this->_input[i] == '.')
			dot++;
	}
	return (true);
}

bool	ScalarConverter::isLiteral(void) const
{
	if (!this->_input.compare("nan") || !this->_input.compare("nanf")
		|| !this->_input.compare("+inf") || !this->_input.compare("+inff")
		|| !this->_input.compare("-inf") || !this->_input.compare("-inff"))
		return (true);
	return (false);
}

// Print
void	ScalarConverter::printChar(void) const
{
	if (this->isLiteral() || (!std::isprint(this->_i) && (this->_i >= 127)))
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(this->_i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->getChar() << "'" << std::endl;
}

std::ostream & operator<<(std::ostream  &o, const ScalarConverter & rhs)
{
	o << "char: "; rhs.printChar();
	o << std::endl;
	o << "int: "; rhs.printInt();
	o << std::endl;
	o << "float: "; rhs.printFloat();
	o << std::endl;
	o << "double: "; rhs.printDouble();
	o << std::endl;
	return (o);
}

// Exceptions
const char * ScalarConverter::InputTypeException::what() const throw()
{
	return ("Error: Input type is unknown");
}