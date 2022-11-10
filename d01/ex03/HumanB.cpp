/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:14:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 07:01:16 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const & name) 
	: _name(name), _weapon(NULL)
{
	std::cout << "A new HumanB is created without weapon. His name is "
			  << this->_name << std::endl;
}

HumanB::HumanB(std::string const & name, Weapon * weapon) 
	: _name(name), _weapon(weapon)
{
	std::cout << "A new HumanB is created. His name is " << this->_name
			  << "and is weapon type is " << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB name(" << this->_name << ") is destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon * weapon)
{
	this->_weapon = weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() 
				  << std::endl;
	}
}
