/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:32:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 08:54:16 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

/* ************************************************************************** */
/*									WEAPON									  */
/*																			  */
/* ************************************************************************** */

class Weapon 
{

	public:

		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		
		const std::string	&getType(void) const;
		void				setType(std::string type);


	private:

		std::string _type;
		

};

#endif
