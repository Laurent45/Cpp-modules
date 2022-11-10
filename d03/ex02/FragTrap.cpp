/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:44:50 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/10 14:28:04 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

//	Canonical form
FragTrap::FragTrap(void) : ClapTrap()
{
	this->_health = FRAG_HEALTH;
	this->_energyPoints = FRAG_ENERGY;
	this->_attackDamage = FRAG_ATTACK;

	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap desructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy._name)
{
	this->_health = copy._health;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;

	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	std::cout << "FragTrap assignment copy called" << std::endl;
	return *this;
}

// Constructors
FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	this->_health = FRAG_HEALTH;
	this->_energyPoints = FRAG_ENERGY;
	this->_attackDamage = FRAG_ATTACK;

	std::cout << "FragTrap constructor (name = " << name << ") called" << std::endl;
}

// Members methods
void	FragTrap::highFivesGuys(void) const
{
	std::cout << "High fives request" << std::endl;
}

/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */

std::ostream & operator<<(std::ostream & out, FragTrap const & fragTrap)
{
	out << "FragTrap(name: " << fragTrap.getName() << ", "
		<< "health: " << fragTrap.getHealth() << ", "
	    << "energy points: " << fragTrap.getEnergyPoints() << ", "
		<< "attack damage: " << fragTrap.getAttackDamage() << ")"
		<< std::endl;
	return out;
}
