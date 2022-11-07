/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:43:10 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/07 14:53:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("type unknown")
{
	std::cout << "A new weapon is created without type" << std::endl;
}

Weapon::Weapon(std::string const & type) : _type(type)
{
	std::cout << "A new weapon is created, his is type: " 
			  << this->_type << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "A weapon type(" << this->_type << ") "
			  << "called his destructor" << std::endl;
}

std::string	const &	Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string const & type)
{
	this->_type = type;
}
