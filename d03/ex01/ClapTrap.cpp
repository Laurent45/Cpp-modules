/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:22:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/03 08:30:02 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
ClapTrap::ClapTrap(void) 
	: _name("default"), _health(DEFAULT_HEALTH), _energyPoints(DEFAULT_ENERGY)
	  , _attackDamage(DEFAULT_ATTACK)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copy)
	: _name(copy._name), _health(copy._health), _energyPoints(copy._energyPoints),
	_attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap assignement copy called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

// Constructors
ClapTrap::ClapTrap(std::string const & name)
	: _name(name), _health(DEFAULT_HEALTH), _energyPoints(DEFAULT_ENERGY)
	  , _attackDamage(DEFAULT_ATTACK)
{
	std::cout << "ClapTrap constructor (name = " << name << ") called" << std::endl;
}

// Members methods
void	ClapTrap::attack(const std::string & target)
{
	std::cout << "ClapTrap " << this->_name 
			  << " called attack(" << target << ")" << std::endl;

	if (!canAct())
		return ;
	this->_energyPoints--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name 
			  << " called takeDamage(" << amount << ")" << std::endl;

	if (this->_health == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
	else
	{
		this->_health = amount > this->_health ? 0 : this->_health - amount;
		std::cout << "ClapTrap " << this->_name << " takes "<< amount << " damages!"
				  << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name 
			  << " called beRepaired(" << amount << ")" << std::endl;

	if (!canAct())
		return ;
	this->_energyPoints--;
	if (this->_health == UINT_MAX)
		return ;
	this->_health = (UINT_MAX - this->_health < amount) ? UINT_MAX : this->_health + amount;

	std::cout << "ClapTrap " << this->_name << " won " << amount << " health points!"
			  << std::endl;
}


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

// Members methods
bool	ClapTrap::canAct(void) const
{
	if (this->_health > 0 && this->_energyPoints > 0)
		return true;
	(this->_health == 0) ? 
		std::cout << "ClapTrap " << this->_name << " can't do anything. It is dead"
		: std::cout << "ClapTrap " << this->_name << " can't do anything. It doesn't have enough energy health";
	std::cout << std::endl;
	return false;
}


/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */

std::ostream & operator<<(std::ostream & out, ClapTrap const & clapTrap)
{
	out << "ClapTrap(name: " << clapTrap._name << ", "
		<< "health: " << clapTrap._health << ", "
	    << "energy points: " << clapTrap._energyPoints << ", "
		<< "attack damage: " << clapTrap._attackDamage << ")"
		<< std::endl;
	return out;
}
