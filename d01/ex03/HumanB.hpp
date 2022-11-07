/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:14:19 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/07 14:51:49 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

/* ************************************************************************** */
/*									HUMAN_B									  */
/*																			  */
/* ************************************************************************** */

class HumanB 
{

	public:
		HumanB(std::string const & name);
		HumanB(std::string const & name, Weapon * weapon);
		~HumanB(void);

		void	setWeapon(Weapon * weapon);

		void	attack(void) const;

	private:
		
		std::string	_name;
		Weapon *	_weapon;

		HumanB(void);

};

#endif
