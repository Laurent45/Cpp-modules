/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:41:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 09:03:55 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap st1("James");
	ScavTrap st2(st1);
	ScavTrap st3;

	st3 = st2;
	
	std::cout << std::endl;
	std::cout << st1;
	st1.attack("Kobe");
	std::cout << st1;
	st1.guardGate();
	st1.takeDamage(12);
	std::cout << st1;

	return 0;
}
