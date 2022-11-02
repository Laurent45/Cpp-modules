/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:22:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/02 16:19:10 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
ClapTrap::ClapTrap(void) 
	: _name("default"), _points(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copy)
	: _name(copy._name), _points(copy._points), _energyPoints(copy._energyPoints),
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
		this->_points = rhs._points;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

// Constructors
ClapTrap::ClapTrap(std::string const & name)
	: _name(name), _points(10), _energyPoints(10), _attackDamage(0)
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

	if (this->_points == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
	else
	{
		this->_points = amount > this->_points ? 0 : this->_points - amount;
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
	this->_points += amount;

	std::cout << "ClapTrap " << this->_name << " won " << amount << " points!"
			  << std::endl;
}



/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

// Members methods
bool	ClapTrap::canAct(void) const
{
	if (this->_points > 0 && this->_energyPoints > 0)
		return true;
	(this->_points == 0) ? 
		std::cout << "ClapTrap " << this->_name << " can't do anything. It is dead"
		: std::cout << "ClapTrap " << this->_name << " can't do anything. It doesn't have enough energy points";
	std::cout << std::endl;
	return false;
}


/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */
std::ostream & operator<<(std::ostream & out, ClapTrap const & clapTrap)
{
	out << "ClapTrap(" 
		<< "name: " << clapTrap._name << ", "
		<< "points: " << clapTrap._points << ", "
		<< "energy points: " << clapTrap._energyPoints << ", "
		<< "attack damage: " << clapTrap._attackDamage << ")"
		<< std::endl;
	return out;
}
