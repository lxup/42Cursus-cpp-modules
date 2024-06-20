/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:56:56 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/20 11:56:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<int>		_v;
		std::list<int>			_l;

		void		checkArgs(int ac, char **av);
		static bool	isDigit(std::string const &str);

		// Prints
		static void	printVector(std::vector<int> const &v);
		static void	printList(std::list<int> const &l);

		/* ==================== MERGE SORT ==================== */
		// Vector
		static void	mergeSortVector(std::vector<int> &v);
		// List
		static void	mergeSortList(std::list<int> &l);
		/* ==================================================== */
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &src);

		// Utils
		static int		ft_stoi(const std::string &input);
		static float	ft_stof(const std::string &input);
		static double	ft_stod(const std::string &input);
};

#endif // PMERGEME_HPP
