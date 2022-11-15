/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:38:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/15 13:43:25 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Bureaucrat::Bureaucrat(void) : _name(""), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
	: _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;

	std::cout << "Bureaucrat copy assignment called" << std::endl;
	return (*this);
}

// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name) , _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	std::cout << "Bureaucrat constructor called (name: " << name << ", grade: " << grade << ")" << std::endl;
}

// Getteurs
std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Operator overload
Bureaucrat &	Bureaucrat::operator++(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
	return (*this);
}

Bureaucrat &	Bureaucrat::operator--(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
	return (*this);
}

// Members methods
void	Bureaucrat::signForm(AForm & form) const
{
	if (form.isSigned())
		std::cout << "Form is already signed"<< std::endl;
	else
	{
		if (isAllowed(form.getGradeToSigned()))
		{
			std::cout << *this << " signed " << form << std::endl; 
			form.setSigned(true);
		}
		else
			std::cout << *this << " couldn't sign " << form
					  << " because grade's bureaucrat is too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm & form) const
{
	bool formSigned = form.isSigned();
	bool allowExec = isAllowed(form.getGradeToExec());

	if (formSigned && allowExec)
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
		return ;
	}
	if (!formSigned)
		std::cout << "Form can't exec because it isn't signed" << std::endl;
	else
		std::cout << "Form can't exec because bureaucrat hasn't enough grade" << std::endl;
}

// Exception classes
const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Exception: Bureaucrat's grade is too high";
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Exception: Bureaucrat's grade is too low";
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */
bool	Bureaucrat::isAllowed(int gradeRequirement) const
{
	if (this->_grade > gradeRequirement)
		return (false);
	return (true);
}

/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */
std::ostream &	operator<<(std::ostream & out, Bureaucrat const & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	return out;
}
