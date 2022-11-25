/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:39:35 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/25 13:00:12 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

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
		std::cout << tmpInt[i] << std::endl;

	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}

	return (0);
}

