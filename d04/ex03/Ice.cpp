/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:38:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/09 08:33:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice default destructor called" << std::endl;
}

Ice::Ice(Ice const & copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &	Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;

	std::cout << "Ice copy assignment called" << std::endl;
	return (*this);
}

// Members methods
AMateria *	Ice::clone(void) const
{
	std::cout << "A clone of Ice created" << std::endl;

	return (new Ice(*this));
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


