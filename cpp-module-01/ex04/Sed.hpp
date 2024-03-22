/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:14:38 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 19:53:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <iostream>
# include <fstream>
# include <cstdlib>

class Sed
{
	private:
		std::string		_filename;
		std::ifstream	_in;
	public:
		Sed( std::string filename );
		~Sed( void );

		void	replace( std::string s1, std::string s2 );
};

#endif // SED_HPP
