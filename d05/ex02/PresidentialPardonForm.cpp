/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:40:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 13:35:55 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", "", PRES_SIGNED_GRADE, PRES_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy)
	: AForm(copy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		this->setSigned(rhs.isSigned());

	std::cout << "PresidentialPardonForm copy assignment called" << std::endl;
	return (*this);
}

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, PRES_SIGNED_GRADE, PRES_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm constructor called with parameters" << std::endl;
}

// Member Function
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkRequirements(executor);
	}
	catch (std::exception & e)
	{
		throw ;
	}

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
	std::cout << GRN "Form executed !" NC << std::endl;
}
