/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:06:02 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 08:06:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/* ************************************************************************** */
/*									ZOMBIE									  */
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
