/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:57:11 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 15:59:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

template <>
std::string getContainerType<std::deque<int> >() {
	return "deque<int>";
}

// Constructor (void)
template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _data(), _time(DEFAULT_TIME), _odd(-1)
{
	return ;
}

// Constructor (char **av)
template <typename Container>
PmergeMe<Container>::PmergeMe(char **av) : _data(), _time(DEFAULT_TIME), _odd(-1)
{
	for (int i = 0; av[i]; i++)
	{
		if (!isDigit(av[i]))
			throw std::invalid_argument("please provide only positive numbers -> " + std::string(av[i]));
		_data.push_back(ft_stoi(av[i]));
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

// Sort
template <typename Container>
void	PmergeMe<Container>::sort(void)
{
	if (this->_data.size() < 2)
		return ;
	clock_t					startClock = clock();
	std::vector<pair_type>	pairs = generatePairs(this->_data);
	// Sort pairs
	sortPairs(pairs);
	// Case only one odd element
	if (!pairs.size())
	{
		this->_data.clear();
		this->_data.push_back(this->_odd);
	}
	else
		insertionSort(pairs);
	// get final time
	this->_time = static_cast<double>(clock() - startClock) / CLOCKS_PER_SEC;
}

// Sort functions
template <typename Container>
std::vector<typename PmergeMe<Container>::pair_type>	PmergeMe<Container>::generatePairs(Container &data)
{
	std::vector<pair_type>	pairs;
	
	// Protect the function
	if (data.size() < 2)
		return (pairs);
	// If the size of the data is odd, we store the last element
	if (data.size() % 2)
	{
		this->_odd = data.back();
		data.pop_back();
	}
	// We generate the pairs
	for (size_t i = 0; i < this->_data.size(); i += 2)
	{
		std::pair<int, int> pair = std::make_pair(this->_data[i], this->_data[i + 1]);

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
		pairs.push_back(pair);
	}
	return (pairs);
}

// generatePairs functions variants for specific containers
// List
template <>
std::vector<std::pair<int, int> >	PmergeMe<std::list<int> >::generatePairs(std::list<int> &data)
{
	std::vector<std::pair<int, int> >	pairs;
	std::list<int>::iterator 			it = data.begin();
	
	// Protect the function
	if (data.size() < 2)
		return (pairs);
	// If the size of the data is odd, we store the last element
	if (data.size() % 2)
	{
		this->_odd = data.back();
		data.pop_back();
	}
	// We generate the pairs for list
	while (it != data.end())
	{
		std::pair<int, int> pair = std::make_pair(*it, *(++it));

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
		pairs.push_back(pair);
		it++;
	}
	return (pairs);
}

// Sort pairs
template <typename Container>
void	PmergeMe<Container>::sortPairs(std::vector<pair_type> &pairs)
{
	if (pairs.size() < 2)
		return ;
	size_type				middle = pairs.size() / 2;
	std::vector<pair_type>	left(pairs.begin(), pairs.begin() + middle);
	std::vector<pair_type>	right(pairs.begin() + middle, pairs.end());
	sortPairs(left);
	sortPairs(right);
	// Merge sorted pairs
	size_type	leftIdx = 0;
	size_type	rightIdx = 0;
	size_type	pairsIdx = 0;
	while (leftIdx < left.size() && rightIdx < right.size())
	{
		if (left[leftIdx].first < right[rightIdx].first)
			pairs[pairsIdx++] = left[leftIdx++];
		else
			pairs[pairsIdx++] = right[rightIdx++];
	}
	while (leftIdx < left.size())
		pairs[pairsIdx++] = left[leftIdx++];
	while (rightIdx < right.size())
		pairs[pairsIdx++] = right[rightIdx++];
}

// template <typename Container>
// int_vector PmergeMe<Container>::generate_indexes(size_t size) {
//     int_vector indexes;
//     int jacobsthalSequence[size + 1];

//     jacobsthalSequence[0] = 0;
//     jacobsthalSequence[1] = 1;
//     int lastJacobsthalNumber = 2;

//     for (size_t i = 2; indexes.size() < size; i++)
//     {
//         // Generate the next Jacobsthal number
//         jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

//         // Push the jacobsthal number
//         i != 2 ? indexes.push_back(jacobsthalSequence[i]) : (void)0;

//         // Push back the indexes between the last Jacobsthal number and the current one
//         for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
//             indexes.push_back(j);

//         // Update the last Jacobsthal number
//         lastJacobsthalNumber = jacobsthalSequence[i];
//     }
//     return (indexes);
// }

template <typename Container>
std::vector<int>	PmergeMe<Container>::generateIndexes(size_t size)
{
	std::vector<int>	indexes;
	std::vector<int>	jacobsthal = generateJacobsthal(size + 1);

	int lastJacobsthal = 2;
	for (size_t i = 2; indexes.size() < size; i++)
	{
		if (i != 2)
			indexes.push_back(jacobsthal[i]);
		for (int j = jacobsthal[i] - 1; j > lastJacobsthal; j--)
			indexes.push_back(j);
		lastJacobsthal = jacobsthal[i];
	}
	return (indexes);
}


template <typename Container>
int		PmergeMe<Container>::binarySearch(int l, int r, int x)
{
	if (l <= r)
	{
		int		mid = (r + l) / 2;
		if (this->_data[mid] == x)
			return mid;
		if (this->_data[mid] > x)
			return binarySearch(l, mid - 1, x);
		return binarySearch(mid + 1, r, x);
	}
	return (l);
}

// binarySearch functions variants for specific containers
// List
template <>
int		PmergeMe<std::list<int> >::binarySearch(int l, int r, int x)
{
	if (l <= r)
	{
		int		mid = (r + l) / 2;
		std::list<int>::iterator it = this->_data.begin();
		std::advance(it, mid);
		if (*it == x)
			return mid;
		if (*it > x)
			return binarySearch(l, mid - 1, x);
		return binarySearch(mid + 1, r, x);
	}
	return (l);
}

template <typename Container>
void	PmergeMe<Container>::insertionSort(std::vector<pair_type> &pairs)
{
	size_t					pair_size = pairs.size();
	std::vector<int>		indexes = generateIndexes(this->_data.size());
	this->_data.clear();
	// Push the second first element because we know it's the smallest
	this->_data.push_back(pairs[0].second);
	// Add all first elements to the data
	for (size_t i = 0; i < pair_size; i++)
		this->_data.push_back(pairs[i].first);
	// Add all second elements to the data using indexes and binary search
	for (size_t i = 0; i < indexes.size(); i++)
	{
		if (size_t(indexes[i] - 1) >= pair_size)
			continue ;
		int binaryIdx = binarySearch(0, this->_data.size() - 1, pairs[indexes[i] - 1].second);
		this->_data.insert(this->_data.begin() + binaryIdx, pairs[indexes[i] - 1].second);
	}
	// Add the last odd element
	if (this->_odd != -1)
	{
		int binaryIdx = binarySearch(0, this->_data.size() - 1, this->_odd);
		this->_data.insert(this->_data.begin() + binaryIdx, this->_odd);
	}
}

// insertionsort functions variants for specific containers
// List
template <>
void	PmergeMe<std::list<int> >::insertionSort(std::vector<pair_type> &pairs)
{
	size_t					pair_size = pairs.size();
	std::vector<int>		indexes = generateIndexes(this->_data.size());
	
	this->_data.clear();
	// Push the second first element because we know it's the smallest
	this->_data.push_back(pairs[0].second);
	// Add all first elements to the data
	for (size_t i = 0; i < pair_size; i++)
		this->_data.push_back(pairs[i].first);
	// Add all second elements to the data using indexes and binary search
	for (size_t i = 0; i < indexes.size(); i++)
	{
		if (size_t(indexes[i] - 1) >= pair_size)
			continue ;
		int binaryIdx = binarySearch(0, this->_data.size() - 1, pairs[indexes[i] - 1].second);
		std::list<int>::iterator it = this->_data.begin();
		std::advance(it, binaryIdx);
		this->_data.insert(it, pairs[indexes[i] - 1].second);
	}
	// Add the last odd element
	if (this->_odd != -1)
	{
		int binaryIdx = binarySearch(0, this->_data.size() - 1, this->_odd);
		std::list<int>::iterator it = this->_data.begin();
		std::advance(it, binaryIdx);
		this->_data.insert(it, this->_odd);
	}
}

template <typename Container>
std::vector<int>	PmergeMe<Container>::generateJacobsthal(size_t size)
{
    std::vector<int> jacobsthal(size < 2 ? 2 : size + 1);

    jacobsthal[0] = 0;
	jacobsthal[1] = 1;
	for (size_t i = 2; i <= size; i++) {
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
	}
    return jacobsthal;
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
bool	PmergeMe<Container>::isDigit(std::string const &str)
{
	long	nb = 0;
	size_t	i = 0;
	int		sign = 1;
	int		multipleSign = 0;
	if (str.empty())
		throw std::invalid_argument("you must provide a number");
	while (iswspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (multipleSign > 0)
			throw std::invalid_argument("please provide only one sign");
		if (str[i] == '-')
			sign = -sign;
		i++;
		multipleSign++;
	}
	if (!isdigit(str[i]))
		throw std::invalid_argument("you must provide a number");
	while (isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			throw std::invalid_argument("please provide a number between INT_MIN and INT_MAX");
	}
	if (sign == -1)
		throw std::invalid_argument("please provide only positive numbers");
	return (true);
}


// Prints
template <typename Container>
void	PmergeMe<Container>::print(void) const
{
	for (typename Container::const_iterator it = _data.begin(); it != _data.end(); it++)
		(it == _data.begin()) ? std::cout << *it : std::cout << " " << *it;
}

template <typename Container>
void	PmergeMe<Container>::time(void) const
{
	std::cout << "Time to process a range of " << this->_data.size()
		<< " element" << (this->_data.size() > 1 ? "s" : "") << " with std::" << getContainerType<Container>()
		<< " : " << std::fixed << std::setprecision(5) << this->_time << "us" << std::endl;
}

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

// Surcharged operators
template <typename Container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<Container> const &src)
{
	for (typename Container::const_iterator it = src._data.begin(); it != src._data.end(); it++)
		os << *it << " ";
	os << std::endl;
	return (os);
}

// Explicit instantiation for all compatible types (without this, we cannot compile the code)
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::list<int> >;
template class PmergeMe< std::deque<int> >;
// template class PmergeMe< std::set<int> >;
// template class PmergeMe< std::map<int, int> >;
// add more if you need to use more containers
