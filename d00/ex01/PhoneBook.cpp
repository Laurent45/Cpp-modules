/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:22:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/24 10:19:35 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

/* ************************************************************************** */
// MEMBERS FUNCTIONS
/* ************************************************************************** */

/*									PUBLIC									  */

void	PhoneBook::addContact(void)
{
	int		contactIndex = PhoneBook::_nbContact % CONTACT_MAX;

	this->_contacts[contactIndex].setFirstName(_getContactField("First name"));
	this->_contacts[contactIndex].setLastName(_getContactField("Last name"));
	this->_contacts[contactIndex].setNickName(_getContactField("Nick name"));
	this->_contacts[contactIndex].setPhoneNumber(_getContactField("Phone number"));
	this->_contacts[contactIndex].setDarkestSecret(_getContactField("Darkest secret"));
	std::cout << "A new contact has been saved" << std::endl;
	PhoneBook::_nbContact++;
}

void	PhoneBook::search(void) const
{
	std::string	index;
	int			idx;
	bool		validIndex;

	_printContacts();
	if (PhoneBook::_nbContact == 0)
		return;
	do
	{
		std::cout << "\n*************" << std::endl;
		std::cout << "Enter index: ";
		std::getline(std::cin, index);
		if (!std::cin.good())
		{
			std::cout << "\nExit\n";
			exit(0);
		}
		validIndex = _isValidIndex(index, &idx);
		if (!validIndex)
			std::cout << "Index or format incorrect, retry" << std::endl;
	} while (!validIndex);
	_printContact(idx);
}

/*									PRIVATE									  */

void	PhoneBook::_printContact(int index) const
{
	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::_printContacts(void) const
{
	int	i = 0;

	if (this->_contacts[0].getNickName().empty())
	{
		std::cout << "No contact saved" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	while (i < CONTACT_MAX && !this->_contacts[i].getFirstName().empty())
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";
		_printRule(this->_contacts[i].getFirstName());
		std::cout << "|";
		_printRule(this->_contacts[i].getLastName());
		std::cout << "|";
		_printRule(this->_contacts[i].getNickName());
		std::cout << std::endl;
		i++;
	}
}

void	PhoneBook::_printRule(std::string str) const
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

std::string		PhoneBook::_getContactField(std::string contactField) const
{
	std::string		field;

	do
	{
		std::cout << contactField << " -> ";
		std::getline(std::cin, field);
		if (!std::cin.good())
		{
			std::cout << "\nExit\n";
			exit(0);
		}
		if (field.empty())
			std::cout << "Empty field is not allow" << std::endl;
	} while (field.empty());
	return (field);
}

bool	PhoneBook::_isValidIndex(std::string index, int *idx) const
{
	for (size_t i = 0; i < index.length(); i++)
	{
		if (!std::isdigit(index[i]))
				return (false);
	}
	*idx = std::atoi(index.c_str());
	if (*idx < CONTACT_MAX && *idx < PhoneBook::_nbContact)
		return (true);
	return (false);
}

/* ************************************************************************** */
// STATIC
/* ************************************************************************** */
int PhoneBook::_nbContact = 0;

