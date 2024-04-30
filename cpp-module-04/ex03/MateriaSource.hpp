/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:11:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/04/30 17:13:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static int const _materiaSize = 4;
		AMateria *_materia[_materiaSize];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource();

		MateriaSource & operator=(MateriaSource const &src);

		void learnMateria(AMateria * materia);
		AMateria* createMateria(std::string const & type);
};

#endif
