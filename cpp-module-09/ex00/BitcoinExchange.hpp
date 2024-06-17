/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:00:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 21:06:31 by lquehec          ###   ########.fr       */
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

# include "LibraryConverter.hpp"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

		static void readFile(std::string filename);
		static void	checkDate(std::string date);

		static bool		isLeapYear(int year);
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		void exchange(const char *filename);
		void printData(void) const;

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
		class DataHeaderFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class EmptyDataException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // BITCOINEXCHANGE_HPP
