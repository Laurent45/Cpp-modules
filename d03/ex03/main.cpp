/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:41:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 14:39:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	FragTrap fragTrap;
	std::cout << fragTrap;
	ScavTrap scavTrap;
	std::cout << scavTrap << std::endl;;

	DiamondTrap dt("Meliodas");
	std::cout << dt;
	dt.whoAmI();
	dt.attack("toto");
	std::cout << dt;
	std::cout << std::endl;

	return 0;
}
