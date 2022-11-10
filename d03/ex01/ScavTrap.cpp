/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:19 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/10 14:15:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
ScavTrap::ScavTrap(void) : ClapTrap() 
{
	this->_health = SCAV_HEALTH;
	this->_energyPoints = SCAV_ENERGY;
	this->_attackDamage = SCAV_ATTACK;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy._name)
{
	this->_health = copy._health;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;

	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap desructor called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	std::cout << "ScavTrap assignment copy called" << std::endl;
	return *this;
}

// Constructors
ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	this->_health = SCAV_HEALTH;
	this->_energyPoints = SCAV_ENERGY;
	this->_attackDamage = SCAV_ATTACK;

	std::cout << "ScavTrap constructor (name = " << name << ") called" << std::endl;
}

// Members methods
void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->_name 
			  << " called attack(" << target << ")" << std::endl;

	if (!ClapTrap::canAct())
		return ;
	this->_energyPoints--;

	std::cout << "ScavTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!"
			  << std::endl;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name << " is now in keeper mode" << std::endl;
}
