/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:00:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 21:08:57 by lquehec          ###   ########.fr       */
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
		throw EmptyDataException();
	std::getline(file, line);
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	if (line != "date,exchange_rate")
		throw DataHeaderFormatException();
	while (std::getline(file, line))
	{
		double value;
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		ss >> value;
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


void BitcoinExchange::readFile(std::string filename)
{
	std::string	line;

	// Open file
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw FileException();
	if (file.peek() == std::ifstream::traits_type::eof())
		throw FileException();

	// Check header
	std::getline(file, line);
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	if (line != "date | value")
		throw FileFormatException();
	
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
			checkDate(date);
			std::cout << "Date: " << date << " | Value: " << value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}

void BitcoinExchange::checkDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw InvalidDateException();
	int year = LibraryConverter::ft_stoi(date.substr(0, 4));
	int month = LibraryConverter::ft_stoi(date.substr(5, 2));
	int day = LibraryConverter::ft_stoi(date.substr(8, 2));
	
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
	this->readFile(filename);
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
void BitcoinExchange::printData(void) const
{
	std::cout << "#======================= DATA =======================#" << std::endl;
	for (std::map<std::string, double>::const_iterator it = this->_data.begin(); it != this->_data.end(); it++)
		std::cout << "Date: \t" << it->first << " | Value: \t" << it->second << std::endl;
	std::cout << "#===================================================#" << std::endl;
}

// Exceptions
const char* BitcoinExchange::FileException::what() const throw()
{
	return ("Unable to open file");
}

const char* BitcoinExchange::FileFormatException::what() const throw()
{
	return ("File format is not correct");
}

const char* BitcoinExchange::NoDataException::what() const throw()
{
	return ("Data file isn't found");
}

const char* BitcoinExchange::DataHeaderFormatException::what() const throw()
{
	return ("Header format of data file is not correct");
}

const char* BitcoinExchange::EmptyDataException::what() const throw()
{
	return ("Empty data found in file");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Invalid date format");
}

