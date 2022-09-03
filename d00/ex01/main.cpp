/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:31:14 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/03 12:45:37 by lfrederi         ###   ########.fr       */
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
