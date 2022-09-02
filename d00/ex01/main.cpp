/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:31:14 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/02 19:31:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;

	for (int i = 0; i < CONTACT_MAX + 1; i++)
	{
		phoneBook.addContact();
		std::cout << std::endl;
		phoneBook.search();
		std::cout << std::endl;
	}

	return 0;
}
