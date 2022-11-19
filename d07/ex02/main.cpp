/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:39:35 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/19 09:21:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Array<int> arrayInt(5);
	Array<int> tmpInt(2);

	for (unsigned int i = 0; i < arrayInt.size(); i++)
		arrayInt[i] = i + 1;

	for (unsigned int i = 0; i < arrayInt.size(); i++)
		std::cout << arrayInt[i] << std::endl;;
	
	tmpInt[0] = 42;
	tmpInt[1] = 21;
	arrayInt = tmpInt;

	std::cout << std::endl;

	for (unsigned int i = 0; i < arrayInt.size(); i++)
		std::cout << arrayInt[i] << std::endl;;

	std::cout << std::endl;

	for (unsigned int i = 0; i < tmpInt.size(); i++)
		std::cout << tmpInt[i] << std::endl;;

	try {
		arrayInt[0] = 424242;
		arrayInt[1] = 212121;
		arrayInt[2] = 212121;
	} catch (std::exception & e) {
		std::cerr << "Invalid index: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	for (unsigned int i = 0; i < arrayInt.size(); i++)
		std::cout << arrayInt[i] << std::endl;;

	std::cout << std::endl;

	for (unsigned int i = 0; i < tmpInt.size(); i++)
		std::cout << tmpInt[i] << std::endl;;

	return (0);
}

