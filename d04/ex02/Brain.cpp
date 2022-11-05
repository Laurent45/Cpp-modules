/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:08:07 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/04 16:35:38 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const & copy)
{
	for (int i = 0; i < NB_IDEAS; i++)
		this->_ideas[i] = copy._ideas[i];

	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &	Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < NB_IDEAS; i++)
			this->_ideas[i] = rhs._ideas[i];
	}

	std::cout << "Brain copy assignment called" << std::endl;
	return (*this);
}


// Constructors


// Destructor


// Members methods


/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

//	Static attributes


// Static methods


// Constructor


