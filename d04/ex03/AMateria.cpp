/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:39:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/06 20:03:39 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
AMateria::AMateria(void) : _collected(false)
{
	std::cout << "Amateria default constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor called" << std::endl;
}

AMateria::AMateria(AMateria const & copy)
	: _type(copy._type), _collected(copy._collected)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &	AMateria::operator=(const AMateria & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_collected = rhs._collected;
	}

	std::cout << "AMateria copy assignment called" << std::endl;
	return (*this);
}

// Constructors
AMateria::AMateria(std::string const & type) : _type(type), _collected(false)
{
	std::cout << "AMateria constructor (type: " << type << ") called" << std::endl;
}

// Members methods
std::string const &	AMateria::getType(void) const
{
	return this->_type;
}

bool	AMateria::isCollected(void) const
{
	return this->_collected;
}

void	AMateria::setCollected(bool newStatus)
{
	this->_collected = newStatus;
}
/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


