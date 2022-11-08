/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/06 19:21:49 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define MAX_ITEMS	4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria * _items[MAX_ITEMS] = {NULL};

	public:
		
		Character(void);
		~Character(void);
		Character(Character const & copy);
		Character &	operator=(Character const & rhs);

		virtual std::string const & getName(void) const;
		virtual void equip(AMateria * m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif
