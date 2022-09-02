/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:22:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/02 21:05:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

/* ************************************************************************** */
// MEMBERS FUNCTIONS
/* ************************************************************************** */

void	PhoneBook::addContact(void)
{
	int		contactIndex = PhoneBook::_nbContact % CONTACT_MAX;

	this->_contacts[contactIndex].setFirstName(_getContactField("First name"));
	this->_contacts[contactIndex].setLastName(_getContactField("Last name"));
	this->_contacts[contactIndex].setNickName(_getContactField("Nick name"));
	this->_contacts[contactIndex].setPhoneNumber(_getContactField("Phone number"));
	this->_contacts[contactIndex].setDarkestSecret(_getContactField("Darkest secret"));
	PhoneBook::_nbContact++;
}

void	PhoneBook::search(void) const
{
	std::string	index;
	bool		validIndex;

	_printContacts();
	do
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, index);
		validIndex = _isValidIndex(index);
		if (!validIndex)
			std::cout << "Index or format incorrect, retry" << std::endl;
	} while (!validIndex);
	_printContact(std::stoi(index));
}

void	PhoneBook::_printContact(int index) const
{
	std::cout << this->_contacts[index].getPhoneNumber();
}

void	PhoneBook::_printContacts(void) const
{
	int	i = 0;

	std::cout << std::setw(10) << "INDEX " << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME " << "|";
	std::cout << std::setw(10) << "NICKNAME " << std::endl;
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
	if (i == 0)
		std::cout << "None contact saved" << std::endl;
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
		if (field.empty())
			std::cout << "Empty field is not allow" << std::endl;
	} while (field.empty());
	return (field);
}

bool	PhoneBook::_isValidIndex(std::string index) const
{
	for (int i = 0; i < index.length(); i++)
	{
		if (!std::isdigit(index[i]))
				return (false);
	}
	return (std::stoi(index) < CONTACT_MAX ? true : false);
}

/* ************************************************************************** */
// STATIC
/* ************************************************************************** */
int PhoneBook::_nbContact = 0;

