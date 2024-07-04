/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:00:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 19:25:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::string	line;

	std::ifstream file("data.csv");
	if (!file.is_open())
		throw NoDataException();
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::invalid_argument("empty data found in file");
	std::getline(file, line);
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	if (line.compare("date,exchange_rate") != 0)
		throw std::invalid_argument("header format of data file is not correct");
	while (std::getline(file, line))
	{
		double value;
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		ss >> value;
		// protect date format even if subjet doesn't ask for it
		try {
			checkDate(date);
		} catch (const std::exception &e) {
			throw std::invalid_argument("invalid date format in data file");
		}
		this->_data[date] = value;
	}
	if (this->_data.empty())
		throw NoDataException();
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		this->_data = src._data;
	return (*this);
}

double BitcoinExchange::checkValue(std::string value)
{
	double	val;
	if (value.empty() || std::count(value.begin(), value.end(), '.') > 1) 
		throw InvalidValueException();
	try {
		val = BitcoinExchange::ft_stod(value);
	} catch (std::invalid_argument &e) {
		throw InvalidValueException();
	} catch (std::out_of_range &e) {
		throw ValueOutOfRangeException();
	}
	if (val < MIN_VALUE)
		throw NegativeValueException();
	else if (val > MAX_VALUE)
		throw ValueOutOfRangeException();
	return (val);
}

void BitcoinExchange::checkDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw InvalidDateException();
	int year = BitcoinExchange::ft_stoi(date.substr(0, 4));
	int month = BitcoinExchange::ft_stoi(date.substr(5, 2));
	int day = BitcoinExchange::ft_stoi(date.substr(8, 2));
	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1)
		throw InvalidDateException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		throw InvalidDateException();
	if (month == 2)
	{
		if (day > (isLeapYear(year) ? 29 : 28))
			throw InvalidDateException();
	}
}

// Exchange
void BitcoinExchange::exchange(const char *filename)
{
	std::string	line;

	// Open file
	std::ifstream file(filename);
	if (!file.is_open())
		throw FileException();
	if (file.peek() == std::ifstream::traits_type::eof())
		throw EmptyInputException();

	// Check header
	std::getline(file, line);
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	if (line != "date | value")
		throw FileFormatException();
	
	int lineCount = 0;
	// Read data
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		std::string			value;
		std::getline(ss, date, '|');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		std::getline(ss, value, '\n');
		value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
		try
		{
			if (date.empty())
				throw std::invalid_argument("empty field");
			checkDate(date);
			double valueConverted = checkValue(value);
			printResult(date, valueConverted);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		lineCount++;
	}
	if (lineCount == 0)
		throw EmptyInputException();
	file.close();
}

// Conditions
bool	BitcoinExchange::isLeapYear(int year)
{
	if (year % 4 != 0)
		return (false);
	if (year % 100 != 0)
		return (true);
	if (year % 400 != 0)
		return (false);
	return (true);
}

// Prints
void BitcoinExchange::printResult(std::string date, double value)
{
	if (this->_data.count(date))
		std::cout << date << " => " << value << " = " << this->_data[date] * value << std::endl;
	else
	{
		std::map<std::string, double>::iterator it = this->_data.upper_bound(date);
		if (it == this->_data.begin())
			throw NoPreviousDateException();
		else
		{
			--it;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}
}

void BitcoinExchange::printData(void) const
{
	std::cout << "#======================= DATA =======================#" << std::endl;
	for (std::map<std::string, double>::const_iterator it = this->_data.begin(); it != this->_data.end(); it++)
		std::cout << "Date: \t" << it->first << " | Value: \t" << it->second << std::endl;
	std::cout << "#===================================================#" << std::endl;
}

// Utils
int		BitcoinExchange::ft_stoi(const std::string &input)
{
	int		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stoi: invalid argument");
	return (ret);
}

float	BitcoinExchange::ft_stof(const std::string &input)
{
	float		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stof: invalid argument");
	return (ret);
}

double	BitcoinExchange::ft_stod(const std::string &input)
{
	double		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stod: invalid argument");
	return (ret);
}

// Exceptions
const char* BitcoinExchange::FileException::what() const throw()
{
	return ("could not open file");
}

const char* BitcoinExchange::FileFormatException::what() const throw()
{
	return ("file format is not correct");
}

const char* BitcoinExchange::NoDataException::what() const throw()
{
	return ("data file isn't found");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("invalid date format");
}

const char* BitcoinExchange::InvalidValueException::what() const throw()
{
	return ("invalid value format");
}

const char* BitcoinExchange::ValueOutOfRangeException::what() const throw()
{
	return ("value out of range");
}

const char* BitcoinExchange::NegativeValueException::what() const throw()
{
	return ("not a positive number");
}

const char* BitcoinExchange::EmptyInputException::what() const throw()
{
	return ("empty input file");
}
const char* BitcoinExchange::NoPreviousDateException::what() const throw()
{
	return ("no previous date found");
}
