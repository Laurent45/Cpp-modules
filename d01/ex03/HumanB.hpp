/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:14:19 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 09:13:38 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

/* ************************************************************************** */
/*									HUMAN_B									  */
/*																			  */
/* ************************************************************************** */

class HumanB 
{

	public:
		HumanB(std::string name);
		HumanB(std::string, Weapon *weapon);
		~HumanB(void);

		void	setWeapon(Weapon *weapon);

		void	attack(void) const;

	private:
		
		std::string	_name;
		Weapon		*_weapon;

		HumanB(void);

};

#endif
