/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:07:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 08:07:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie	*zombies = zombieHorde(N_ZOMBIE, ZOMBIE_NAME);
	for (int i = 0; i < N_ZOMBIE; i++)
	{
		std::cout << "index (" << i << ") ";
		zombies[i].announce();
	}

	delete [] zombies;

	return (0);
}
