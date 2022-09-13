/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:42:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/13 18:34:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/* ************************************************************************** */
/*									CLASS									  */
/*																			  */
/* ************************************************************************** */

class Zombie
{

	public:

		Zombie(std::string name);
		~Zombie(void);

		void	announce(void) const;

	private:
		
		std::string	_name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
