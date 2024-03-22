/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:16:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 20:00:59 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed( std::string filename )
{
	this->_filename = filename;
	this->_in.open(filename.c_str());
	if (!this->_in.is_open())
	{
		std::cerr << "Error: could not open infile." << std::endl;
		exit(EXIT_FAILURE);
	}
	// std::cout << "Sed created" << std::endl;
	return ;
}

Sed::~Sed( void ) {
	if (this->_in.is_open())
		this->_in.close();
	// std::cout << "Sed destroyed" << std::endl;
	return ;
}

void	Sed::replace( std::string toFind, std::string toReplace)
{
	std::string		line;
	std::ofstream	out;
	size_t			pos = 0;

	if (!this->_in.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	if (std::getline(this->_in, line, '\0'))
	{
		out.open((this->_filename + ".replace").c_str());
		if (!out.is_open())
		{
			std::cerr << "Error: could not open outfile." << std::endl;
			this->_in.close();
			exit(EXIT_FAILURE);
		}
		pos = line.find(toFind);
		while (pos != std::string::npos)
		{
			line.erase(pos, toFind.length());
			line.insert(pos, toReplace);
			pos = line.find(toFind);
		}
		out << line;
		out.close();
	}
	else
	{
		std::cerr << "Error: could not read file." << std::endl;
		exit(EXIT_FAILURE);
	}
}
