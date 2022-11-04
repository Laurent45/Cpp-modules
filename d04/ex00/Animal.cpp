/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:39:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 15:19:31 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form 
Animal::Animal(void) : _type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const & copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &	Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;

	std::cout << "Animal copy assignment called" << std::endl;
	return (*this);
}

// Constructors
Animal::Animal(std::string const & type) : _type(type)
{
	std::cout << "Animal constructor (type: " << type << ") called" << std::endl;
}

// Destructor


// Members methods
std::string const &	Animal::getType(void) const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound ......." << std::endl;
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor




