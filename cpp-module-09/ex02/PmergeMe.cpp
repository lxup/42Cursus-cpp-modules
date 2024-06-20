/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:57:11 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/20 11:57:16 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac < 2)
		throw std::invalid_argument("please provide at least 1 argument, usage : ./PmergeMe <sequence>");
	checkArgs(ac, av);
	std::cout << "Before: ";
	printVector(_v);
	// Merge sort with vector
	clock_t		startVectorMerge = clock();
	mergeSortVector(_v);
	clock_t		endVectorMerge = clock();
	double		timeVectorMerge = static_cast<double>(endVectorMerge - startVectorMerge) / CLOCKS_PER_SEC * 1000;

	// Merge sort with list
	clock_t		startListMerge = clock();
	mergeSortList(_l);
	clock_t		endListMerge = clock();
	double		timeListMerge = static_cast<double>(endListMerge - startListMerge) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	printVector(_v);
	std::cout << "Time for sorting as vector: " << timeVectorMerge << "us" << std::endl;
	std::cout << "Time for sorting as list: " << timeListMerge << "us" << std::endl;
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_v = src._v;
		this->_l = src._l;
	}
	return (*this);
}


/* ==================== MERGE SORT ==================== */
void	PmergeMe::mergeSortVector(std::vector<int> &v)
{
	(void)v;
}

void	PmergeMe::mergeSortList(std::list<int> &l)
{
	(void)l;
}
/* ==================================================== */

void	PmergeMe::checkArgs(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!isDigit(av[i]))
			throw std::invalid_argument("please provide only numbers -> " + std::string(av[i]));
		_v.push_back(PmergeMe::ft_stoi(av[i]));
		_l.push_back(PmergeMe::ft_stoi(av[i]));
	}
}

bool	PmergeMe::isDigit(std::string const &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

// Prints
void	PmergeMe::printVector(std::vector<int> const &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i + 1 < v.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printList(std::list<int> const &l)
{
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it;
		if (++it != l.end())
			std::cout << " ";
		it--;
	}
	std::cout << std::endl;
}

// Utils
int		PmergeMe::ft_stoi(const std::string &input)
{
	int		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stoi: invalid argument");
	return (ret);
}

float	PmergeMe::ft_stof(const std::string &input)
{
	float		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stof: invalid argument");
	return (ret);
}

double	PmergeMe::ft_stod(const std::string &input)
{
	double		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stod: invalid argument");
	return (ret);
}
