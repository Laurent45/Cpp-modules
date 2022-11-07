/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:58:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/07 14:50:01 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const & name, Weapon & weapon) 
	: _name(name), _weapon(weapon)
{
	std::cout << "A new HumanA is created, his name is " << this->_name
			  << " and his weapon type is " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA name(" << this->_name << ") is destroyed" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() 
			  << std::endl;
}

