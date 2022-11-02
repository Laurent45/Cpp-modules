/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:41:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/02 16:19:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap trap1;
	ClapTrap trap2("Esquanor");
	ClapTrap trap3("Meliodas");
	ClapTrap trap4(trap3);
	ClapTrap trap5("Ban");

	trap1 = trap2;
	std::cout << trap1;
	std::cout << trap2;
	std::cout << trap3;
	std::cout << trap4;
	std::cout << trap5 << std::endl;

	trap1.takeDamage(2);
	std::cout << trap1;
	trap1.attack("Ban");
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.attack("Meliodas");
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.takeDamage(5);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.beRepaired(2);
	std::cout << trap1 << std::endl;

	trap1.beRepaired(2);
	std::cout << trap1;
	trap1.attack("Naruto");
	std::cout << trap1;
	trap1.takeDamage(4);
	std::cout << trap1 << std::endl;

	trap3.takeDamage(11);
	std::cout << trap3;
	trap3.takeDamage(11);
	std::cout << trap3;
	trap3.beRepaired(1);
	std::cout << trap3;
	trap3.attack("Sasuke");
	std::cout << trap3;

	return 0;
}
