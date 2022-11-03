/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:41:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 11:05:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap fg("Jojo");
	std::cout << fg;

	fg.highFivesGuys();
	std::cout << fg;
	fg.takeDamage(UINT_MAX);
	std::cout << fg;
	fg.beRepaired(1);
	std::cout << fg;

	return 0;
}
