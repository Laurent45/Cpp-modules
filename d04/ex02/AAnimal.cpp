/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:39:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 19:52:42 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form 
AAnimal::AAnimal(void) : _type("default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & copy) : _type(copy._type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;

	std::cout << "AAnimal copy assignment called" << std::endl;
	return (*this);
}

// Constructors
AAnimal::AAnimal(std::string const & type) : _type(type)
{
	std::cout << "AAnimal constructor (type: " << type << ") called" << std::endl;
}

// Destructor


// Members methods
std::string const &	AAnimal::getType(void) const
{
	return this->_type;
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor




