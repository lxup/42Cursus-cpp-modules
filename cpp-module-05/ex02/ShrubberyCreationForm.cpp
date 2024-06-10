/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:32 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/10 18:17:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	file;
	std::string		filename = this->_target + "_shrubbery";

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	file << "          .     .  .      +     .      .          ." << std::endl;
	file << "     .       .      .     #       .           ." << std::endl;
	file << "        .      .         ###            .      .      ." << std::endl;
	file << "      .      .   '#:. .:##'##:. .:#'  .      ." << std::endl;
	file << "          .      . '####'###'####'  ." << std::endl;
	file << "       .     '#:.    .:#'###'#:.    .:#'  .        .       ." << std::endl;
	file << "  .             '#########'#########'        .        ." << std::endl;
	file << "        .    '#:.  '####'###'####'  .:#'   .       ." << std::endl;
	file << "     .     .  '#######''##'##''#######'                  ." << std::endl;
	file << "                .'##'#####'#####'##'           .      ." << std::endl;
	file << "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     ." << std::endl;
	file << "      .     '#######'##'#####'##'#######'      .     ." << std::endl;
	file << "    .    .     '#####''#######''#####'    .      ." << std::endl;
	file << "            .     '      000      '    .     ." << std::endl;
	file << "       .         .   .   000     .        .       ." << std::endl;
	file << ".. .. ..................O000O........................ ...... ..." << std::endl;
	file.close();
}