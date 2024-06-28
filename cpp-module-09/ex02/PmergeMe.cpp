/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:57:11 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/27 17:13:43 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructor (void)
template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _data(), _time(0)
{
	return ;
}

// Constructor (char **av)
template <typename Container>
PmergeMe<Container>::PmergeMe(char **av) : _data(), _time(0)
{
	for (int i = 1; av[i]; i++)
	{
		if (isDigit(av[i]))
			throw std::invalid_argument("please provide only numbers -> " + std::string(av[i]));
		_data.push_back(av[i]);
	}
}

// Copy constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe const &src) : _data(src._data), _time(src._time)
{
	return ;
}

// Destructor
template <typename Container>
PmergeMe<Container>::~PmergeMe(void)
{
	return ;
}

// Operator=
template <typename Container>
PmergeMe<Container>	&PmergeMe<Container>::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_data = src._data;
		this->_time = src._time;
	}
	return (*this);
}

// Container type
template <typename Container>
std::string getContainerType();

template <>
std::string getContainerType<std::vector<int> >() {
    return "vector<int>";
}

template <>
std::string getContainerType<std::list<int> >() {
    return "list<int>";
}

// Utils
template <typename Container>
bool	PmergeMe<Container>::isDigit(std::string const &str)
{
	long	nb;
	size_t	i = 0;
	int		sign = 1;
	if (str.empty())
		return (false);
	while (iswspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!isdigit(str[i]))
		return (false);
	while (isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (false);
	}
	if (sign == -1)
		return (false);
	return (nb * sign);
}

// Surcharged operators
template <typename Container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<Container> const &src)
{
	os << "Data: ";
	for (typename Container::const_iterator it = src._data.begin(); it != src._data.end(); it++)
		os << *it << " ";
	os << std::endl;
	return (os);
}



// PmergeMe::PmergeMe(int ac, char **av)
// {
// 	if (ac < 2)
// 		throw std::invalid_argument("please provide at least 1 argument, usage : ./PmergeMe <sequence>");
// 	checkArgs(ac, av);
// 	std::cout << "Before: ";
// 	print(_v);
// 	// Merge sort with vector
// 	clock_t		startVectorMerge = clock();
// 	mergeSort(_v);
// 	clock_t		endVectorMerge = clock();
// 	double		timeVectorMerge = static_cast<double>(endVectorMerge - startVectorMerge) / CLOCKS_PER_SEC * 1000;

// 	// Merge sort with list
// 	clock_t		startListMerge = clock();
// 	mergeSort(_l);
// 	clock_t		endListMerge = clock();
// 	double		timeListMerge = static_cast<double>(endListMerge - startListMerge) / CLOCKS_PER_SEC * 1000;

// 	std::cout << "After: ";
// 	print(_v);
// 	std::cout << "Time for sorting as vector: " << timeVectorMerge << "us" << std::endl;
// 	std::cout << "Time for sorting as list: " << timeListMerge << "us" << std::endl;
// 	return ;
// }

// PmergeMe::PmergeMe(PmergeMe const &src)
// {
// 	*this = src;
// 	return ;
// }

// PmergeMe::~PmergeMe(void)
// {
// 	return ;
// }

// PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
// {
// 	if (this != &src)
// 	{
// 		this->_v = src._v;
// 		this->_l = src._l;
// 	}
// 	return (*this);
// }


// /* ==================== MERGE SORT ==================== */
// void	PmergeMe::mergeSort(std::vector<int> &v)
// {
// 	(void)v;
// }

// void	PmergeMe::mergeSort(std::list<int> &l)
// {
// 	(void)l;
// }
// /* ==================================================== */

// void	PmergeMe::checkArgs(int ac, char **av)
// {
// 	for (int i = 1; i < ac; i++)
// 	{
// 		if (!isDigit(av[i]))
// 			throw std::invalid_argument("please provide only numbers -> " + std::string(av[i]));
// 		_v.push_back(PmergeMe::ft_stoi(av[i]));
// 		_l.push_back(PmergeMe::ft_stoi(av[i]));
// 	}
// }

// bool	PmergeMe::isDigit(std::string const &str)
// {
// 	for (size_t i = 0; i < str.size(); i++)
// 	{
// 		if (!isdigit(str[i]))
// 			return (false);
// 	}
// 	return (true);
// }

// // Prints
// template <typename T>
// void	PmergeMe::print(T const &container)
// {
// 	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

// Utils
template <typename Container>
int		PmergeMe<Container>::ft_stoi(const std::string &input)
{
	int		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stoi: invalid argument");
	return (ret);
}

template <typename Container>
float	PmergeMe<Container>::ft_stof(const std::string &input)
{
	float		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stof: invalid argument");
	return (ret);
}

template <typename Container>
double	PmergeMe<Container>::ft_stod(const std::string &input)
{
	double		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stod: invalid argument");
	return (ret);
}
