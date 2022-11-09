/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:53:29 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 11:53:33 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Character::Character(void)
{
	for (int i = 0; i < MAX_ITEMS; i++)
		this->_items[i] = NULL;

	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character(void)
{
	int i = 0;
	while (i < MAX_ITEMS && this->_items[i])
		delete _items[i++];

	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const & copy) : _name(copy._name)
{
	int i = 0;
	while (i < MAX_ITEMS && copy._items[i])
	{
		this->_items[i] = copy._items[i]->clone();
		i++;
	}
	
	std::cout << "Character copy constructor called" << std::endl;
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		int i = 0;
		while (i < MAX_ITEMS && this->_items[i])
		{
			delete this->_items[i];
			this->_items[i] = NULL;
			i++;
		}

		i = 0;
		while (i < MAX_ITEMS && rhs._items[i])
		{
			this->_items[i] = rhs._items[i]->clone();
			i++;
		}
	}

	std::cout << "Character copy assignment called" << std::endl;
	return (*this);
}

// Constructor
Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < MAX_ITEMS; i++)
		this->_items[i] = NULL;

	std::cout << "Character constructor (name: " << name << ") called" << std::endl;
}

// Members methods
std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria * m)
{
	if (!m)
		return ;

	int i = 0;
	while (i < MAX_ITEMS && this->_items[i])
		i++;
	if (i == MAX_ITEMS)
		std::cout << "Items are full" << std::endl;
	else
	{
		this->_items[i] = m;
		m->setCollected(true);
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_ITEMS)
		return ;
	if (!this->_items[idx])
		return ;
	if (idx == MAX_ITEMS - 1 || this->_items[idx + 1] == NULL)
	{
		this->_items[idx]->setCollected(false);
		this->_items[idx] = NULL;
	}
	else
	{
		int i = idx;
		this->_items[idx]->setCollected(false);
		while (i < MAX_ITEMS - 1 && this->_items[i])
		{
			this->_items[i] = this->_items[i + 1];
			i++;
		}
		this->_items[MAX_ITEMS - 1] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx >= MAX_ITEMS || !this->_items[idx])
		return ;
	this->_items[idx]->use(target);
}


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


