/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:13:32 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/10 14:43:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
DiamondTrap::DiamondTrap(void) : 
	ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	this->_health = FRAG_HEALTH;	
	this->_energyPoints = SCAV_ENERGY;
	this->_attackDamage = FRAG_ATTACK;
	
	std::cout << "DiamondTrap default construcor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) :
	ClapTrap(copy.ClapTrap::_name), FragTrap() , ScavTrap(), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_name = rhs._name;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	std::cout << "DiamondTrap assignment copy called" << std::endl;
	return *this;
}

// Constructors
DiamondTrap::DiamondTrap(std::string const & name) : 
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{

	this->_health = FRAG_HEALTH;	
	this->_energyPoints = SCAV_ENERGY;
	this->_attackDamage = FRAG_ATTACK;

	std::cout << "DiamondTrap constructor (name = " << name << ") called" << std::endl;
}

// Members methods
void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << this->_name
			  << " / ClapTrap name: " << this->ClapTrap::_name
			  << std::endl;
}

std::string		DiamondTrap::getName(void) const
{
	return this->_name;
}

/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */
std::ostream & operator<<(std::ostream & out, DiamondTrap const & diamondTrap)
{
	out << "DiamondTrap(name: " << diamondTrap.getName() << ", "
		<< "health: " << diamondTrap.getHealth() << ", "
		<< "energy points: " << diamondTrap.getEnergyPoints() << ", "
		<< "attack damage: " << diamondTrap.getAttackDamage() << ")"
		<< std::endl;

	return out;
}
