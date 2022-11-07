/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:32:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/07 14:53:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

/* ************************************************************************** */
/*									WEAPON									  */
/*																			  */
/* ************************************************************************** */

class Weapon 
{

	public:

		Weapon(void);
		Weapon(std::string const & type);
		~Weapon(void);
		
		std::string const &	getType(void) const;
		void				setType(std::string const & type);


	private:

		std::string _type;
		

};

#endif
