/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:51:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 19:44:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Dog::Dog(void) : Animal("Dog")
{
	this->_brain = new Brain();

	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;

	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const & copy) : Animal(copy)
{
	this->_brain = new Brain(*copy._brain);

	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_brain = rhs._brain;
		this->_type = rhs._type;
	}
	
	std::cout << "Dog copy assignment called" << std::endl;
	return (*this);
}

// Constructors


// Destructor


// Members methods
void	Dog::makeSound(void) const
{
	std::cout << "Ouawf Ouawf !" << std::endl;
}


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


