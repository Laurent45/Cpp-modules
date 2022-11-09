/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:52:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 08:32:12 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure default destructor called" << std::endl;
}

Cure::Cure(Cure const & copy) : AMateria(copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &	Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;

	std::cout << "Cure copy assignment called" << std::endl;
	return (*this);
}

// Constructors


// Destructor


// Members methods
AMateria *	Cure::clone(void) const
{
	std::cout << "A clone of Cure created" << std::endl;

	return (new Cure(*this));
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


