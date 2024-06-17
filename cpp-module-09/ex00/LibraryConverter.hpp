/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibraryConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:37:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 12:17:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARYCONVERTER_HPP
# define LIBRARYCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>

class LibraryConverter
{
	public:
		static int		ft_stoi(const std::string &input);
		static float	ft_stof(const std::string &input);
		static double	ft_stod(const std::string &input);
};

#endif // LIBRARYCONVERTER_HPP
