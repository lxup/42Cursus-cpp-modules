/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:00:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 19:54:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <string>
# include <algorithm>

# define MIN_VALUE 0
# define MAX_VALUE 1000

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

		void		checkDate(std::string date);
		double	checkValue(std::string value);

		void		printResult(std::string date, double value);

		bool		isLeapYear(int year);
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		void exchange(const char *filename);
		void printData(void) const;

		// Utils
		static int		ft_stoi(const std::string &input);
		static float	ft_stof(const std::string &input);
		static double	ft_stod(const std::string &input);

		// Exceptions
		class FileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FileFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoDataException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ValueOutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NegativeValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class EmptyInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoPreviousDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DateNotReachedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // BITCOINEXCHANGE_HPP
