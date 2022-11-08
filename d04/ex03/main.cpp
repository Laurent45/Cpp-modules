/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:53:56 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/06 13:51:58 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	AMateria * ice = new Ice();
	AMateria * cure = new Cure();
	
	std::cout << std::endl;

	std::cout << "type of ice => " << ice->getType() << std::endl;;
	std::cout << "type of cure => " << cure->getType() << std::endl;

	std::cout << std::endl;

	AMateria * iceClone = ice->clone();
	AMateria * cureClone = cure->clone();
	
	std::cout << std::endl;

	std::cout << "type of iceClone => " << iceClone->getType() << std::endl;;
	std::cout << "type of cureClone => " << cureClone->getType() << std::endl;

	std::cout << std::endl;

	delete ice;
	delete cure;
	delete iceClone;
	delete cureClone;

	return (0);
}
