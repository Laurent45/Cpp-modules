/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:53:29 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/06 20:16:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character(void)
{
	int i = 0;
	while (i < MAX_ITEMS && _items[i])
		delete _items[i++];

	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const & copy)
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
	int i = 0;
	while (i < MAX_ITEMS && this->_items[i])
		delete this->_items[i];

	i = 0;
	while (i < MAX_ITEMS && rhs._items[i])
	{
		this->_items[i] = rhs._items[i]->clone();
		i++;
	}

	std::cout << "Character copy assignment called" << std::endl;
	return (*this);
}

// Members methods
std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria * m)
{
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
	
	int i = idx;
	while ()
	{
		this->_items[]
	}
}


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


