/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:31:14 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/24 10:04:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	do 
	{
		std::cout << "\n***************************************" << std::endl;
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "\nExit\n";
			return 0;
		}
		if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.search();
		else if (input.compare("EXIT") == 0)
			std::cout << "Bye bye!" << std::endl;
		else
			std::cout << "Command unknown, retry" << std::endl;
	} while (input.compare("EXIT") != 0);

	return 0;
}
