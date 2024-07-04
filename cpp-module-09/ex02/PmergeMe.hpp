/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:56:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/04 17:38:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits.h>
# include <iomanip>

// Containers
# include <vector>
# include <list>
# include <deque>
// # include <map>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define DEFAULT_TIME -1


template <typename Container>
class PmergeMe
{
	// Need to declare typedef before using it in the class
	public:
		typedef typename Container::value_type		value_type;
		typedef std::pair <value_type, value_type>	pair_type;
		typedef typename Container::size_type		size_type;
	private:
		Container		_data;
		double			_time;
		value_type		_odd;

		// Bool functions
		static bool	isDigit(std::string const &str);

		// Sort functions
		std::vector<pair_type>	generatePairs(Container &data);
		void					sortPairs(std::vector<pair_type> &pairs);
		void					insertionSort(std::vector<pair_type> &pairs);
		std::vector<int>		generateIndexes(size_t size);
		std::vector<int>		generateJacobsthal(size_t size);
		int						binarySearch(int l, int r, int x);
	public:
		PmergeMe(void);
		PmergeMe(char **av);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &src);

		
		// Sort
		void	sort(void);

		// Prints
		void	print(void) const;
		void	time(void) const;

		// Types
		std::string		getType(void) const;
		
		// Utils
		static int		ft_stoi(const std::string &input);
		static float	ft_stof(const std::string &input);
		static double	ft_stod(const std::string &input);

};

// Surcharged operators
template <typename Container>
std::ostream	&operator<<(std::ostream &o, PmergeMe<Container> const &src);

// class PmergeMe
// {
// 	private:
// 		std::vector<int>		_v;
// 		std::list<int>			_l;

// 		void		checkArgs(int ac, char **av);
// 		static bool	isDigit(std::string const &str);

// 		// Prints
// 		template <typename T>
		
// 		static void	printVector(std::vector<int> const &v);
// 		static void	printList(std::list<int> const &l);

// 		/* ==================== MERGE SORT ==================== */
// 		// Vector
// 		static void	mergeSort(std::vector<int> &v);
// 		// List
// 		static void	mergeSort(std::list<int> &l);
// 		/* ==================================================== */
// 	public:
// 		PmergeMe(int ac, char **av);
// 		PmergeMe(PmergeMe const &src);
// 		~PmergeMe(void);

// 		PmergeMe	&operator=(PmergeMe const &src);

// 		// Utils
// 		static int		ft_stoi(const std::string &input);
// 		static float	ft_stof(const std::string &input);
// 		static double	ft_stod(const std::string &input);
// };

#endif // PMERGEME_HPP
