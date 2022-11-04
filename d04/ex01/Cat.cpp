/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:54 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 19:45:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();

	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;

	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const & copy) : Animal(copy)
{
	this->_brain = new Brain(*copy._brain);

	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &	Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		this->_brain = rhs._brain;
		this->_type = rhs._type;
	}
	
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

// Constructors


// Destructor


// Members methods
void	Cat::makeSound(void) const
{
	std::cout << "Mioauw !" << std::endl;
}


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


