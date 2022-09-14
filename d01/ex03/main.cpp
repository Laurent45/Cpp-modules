/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:07:51 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/14 09:26:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(void)
{
	Weapon clubA = Weapon("crude spiked clubA");
	HumanA bob("Bob", clubA);
	bob.attack();
	clubA.setType("some other type of clubA");
	bob.attack();

	std::cout << std::endl << std::endl;

	Weapon clubB = Weapon("crude spiked clubB");
	HumanB jim("Jim");
	jim.setWeapon(&clubB);
	jim.attack();
	clubB.setType("some other type of clubB");
	jim.attack();

	std::cout << std::endl << std::endl;

	return (0);
}
