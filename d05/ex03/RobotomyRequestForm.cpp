/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:05:57 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 14:15:49 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", "", ROBO_SIGNED_GRADE, ROBO_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy)
	: AForm(copy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		this->setSigned(rhs.isSigned());

	std::cout << "RobotomyRequestForm copy assignment called" << std::endl;
	return (*this);
}

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, ROBO_SIGNED_GRADE, ROBO_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm constructor called with parameters" << std::endl;
}

// Member Function
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		checkRequirements(executor);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
		return ;
	}

	std::cout << "Brrrrrrrrrrrrrrr ...................." << std::endl;
	srand(time(NULL));
	int random = (rand() % 100) + 1;
	if (random > 50)
		std::cout << this->getTarget() << " is now a robot" << std::endl;
	else
		std::cout << this->getTarget() << " isn't set to a robot operation failed" << std::endl;
	std::cout << GRN "Form executed !" NC << std::endl;
}

/* ************************************************************************** */
//						           FUNCTION									  //
/* ************************************************************************** */
std::ostream & operator<<(std::ostream & out, RobotomyRequestForm const & form)
{
	out << "RobotomyRequestForm -> ("
		<< "name: " << form.getName()
		<< ", target: " << form.getTarget()
		<< ", signed: " << (form.isSigned() ? "true": "false")
		<< ", grade to signed: " << form.getGradeToSigned()
		<< ", grade to exec: " << form.getGradeToExec() << ")";
	return (out);
}
