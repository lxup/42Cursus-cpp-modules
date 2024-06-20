/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibraryConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:39:18 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/20 19:38:43 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibraryConverter.hpp"

int		LibraryConverter::ft_stoi(const std::string &input)
{
	int		ret;
	std::istringstream	ss(input);

	ss >> ret;
	// if (ss.fail() || !ss.eof())
	// 	throw std::invalid_argument("stoi: invalid argument");
	return (ret);
}

float	LibraryConverter::ft_stof(const std::string &input)
{
	float		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stof: invalid argument");
	return (ret);
}

double	LibraryConverter::ft_stod(const std::string &input)
{
	double		ret;
	std::istringstream	ss(input);

	ss >> ret;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("stod: invalid argument");
	return (ret);
}
