/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:27:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 15:46:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const & copy)
{
	(void) copy;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void) rhs;
	std::cout << "Intern copy assignment called" << std::endl;
	return (*this);
}

// Members methods
AForm * Intern::makeForm(std::string const & nameForm, std::string const & target) const
{
	AForm * (Intern::*forms[NB_FORM])(std::string const &) const = {
		&Intern::createShrubberyCreationForm
		, &Intern::createRobotomyRequestForm
		, &Intern::createPresidentialPardonForm
	};
	std::string nameForms[NB_FORM] = {
		"shrubbery creation"
		, "robotomy request"
		, "presidential pardon"
	};

	int i = 0;
	while (i < NB_FORM)
	{
		if (nameForm == nameForms[i])
		{
			std::cout << "Intern creates " << nameForm << " form" << std::endl;
			return ((this->*forms[i])(target));
		}
		i++;
	}

	std::cout << "Name form -> " << nameForm << " is unknown" << std::endl;
	return (NULL);
}

AForm *	Intern::createShrubberyCreationForm(std::string const & target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::createRobotomyRequestForm(std::string const & target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *	Intern::createPresidentialPardonForm(std::string const & target) const
{
	return (new PresidentialPardonForm(target));
}
