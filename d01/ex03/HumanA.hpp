/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:48:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/07 14:50:02 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

/* ************************************************************************** */
/*									HUMAN_A									  */
/*																			  */
/* ************************************************************************** */

class HumanA 
{

	public:

		HumanA(std::string const & name, Weapon & weapon);
		~HumanA(void);

		void	attack(void) const;


	private:

		std::string	_name;
		Weapon &	_weapon;

		HumanA(void);

};

#endif
