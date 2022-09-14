/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:08:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 08:08:33 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

#define N_ZOMBIE	15
#define	ZOMBIE_NAME	"Foo"

/* ************************************************************************** */
/*									ZOMBIE									  */
/*																			  */
/* ************************************************************************** */

class Zombie
{

	public:

		Zombie(void);
		~Zombie(void);

		void	setName(std::string name);

		void	announce(void) const;

	private:
		
		std::string	_name;

};

Zombie	*zombieHorde(int N, std::string name);

#endif
