/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:42:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/05 16:08:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

/* ************************************************************************** */
/*									CLASS									  */
/*																			  */
/* ************************************************************************** */

class Zombie
{

	public:

		Zombie(std::string name);
		~Zombie(void);

		void	annonce(void) const;

	private:
		
		std::string	_name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
