/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:54:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 10:21:48 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_MATERIAS	4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria * _materias[MAX_MATERIAS];

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		MateriaSource &	operator=(MateriaSource const & rhs);		

		virtual void learnMateria(AMateria * materia);
		virtual AMateria * createMateria(std::string const & type);
};

#endif
