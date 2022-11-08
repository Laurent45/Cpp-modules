/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:39:51 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/06 20:02:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string _type;
		bool		_collected;

	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(AMateria const & copy);
		AMateria &	operator=(AMateria const & rhs);

		AMateria(std::string const & type);

		std::string const & getType(void) const;
		bool	isCollected(void) const;
		void	setCollected(bool newStatus);
		virtual AMateria * clone(void) const = 0;
		virtual void use(ICharacter& target);
};
#endif

